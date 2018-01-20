// AwesomeBotWithPID.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <Windows.h>
#include <iomanip>

#include "cRobot.h"
#include "cPID.h"

void DrawJitterBar (double jitter, double drawScale);
void DrawRobot (cRobot* pRobot);
void DrawTarget (double x, double y);
void MoveCursorToXY (int x, int y);
void PrintRobotState (cRobot* pRobot);


sPoint2D oldRobotPosition;

int main()
{
	cRobot* pRobby = new cRobot();
	double totalSimTime = 150.0f;			// 15 seconds
	sPoint2D target(30, 10);

	double minSpeed = -3;
	double maxSpeed = +3;

	// Change these to tune the PID
	double Kp = 0.6;  // Proportional gain
	double Ki = 0.1;  // Integral gain
	double Kd = 0.01; // Derivative gain
	
	cPID pid = cPID(0.2, maxSpeed, minSpeed, Kp, Ki, Kd);

	bool bKeepSimulating = true;
	do
	{
		sPoint2D rXY = pRobby->getPosition();

		double speed = pid.calculate(target.x, rXY.x);
		pRobby->setMotorSpeed(speed, 0.0f);

		// **************************************
		// Don't touch this part
		// **************************************
		double frameTime = pRobby->SimulationTimeTick();
		// Done? 
		if (pRobby->getElapsedTime() >= totalSimTime) {
			bKeepSimulating = false;
		}
		PrintRobotState(pRobby);
		DrawRobot(pRobby);
		DrawTarget(target.x, target.y);
		DrawJitterBar(frameTime, 500.0);
		Sleep(20);
		// **************************************
	} while (bKeepSimulating);

	delete pRobby;

	return 0;
}

/**
 *
 */

void DrawJitterBar (double jitter, double drawScale) {
	MoveCursorToXY(0, 3);
	std::cout << "|--------------------";

	int jitLocation = (int)(jitter * drawScale);
	MoveCursorToXY(jitLocation, 3);
	std::cout << "H";
}

/**
 *
 */

void DrawRobot (cRobot* pRobot) {
	MoveCursorToXY((int)oldRobotPosition.x, (int)oldRobotPosition.y);
	std::cout << " ";

	MoveCursorToXY((int)pRobot->getPosition().x, (int)pRobot->getPosition().y);
	std::cout << "O";

	oldRobotPosition = pRobot->getPosition();
}

/**
 *
 */

void DrawTarget (double x, double y) {
	MoveCursorToXY((int) x, (int) y);
	std::cout << "X";
}

/**
 *
 */

void MoveCursorToXY(int x, int y) {
	COORD pos = { (SHORT)x, (SHORT)y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

/**
 *
 */

void PrintRobotState(cRobot* pRobot) {
	MoveCursorToXY(0, 0);
	std::cout << std::setprecision(2) << std::fixed
		<< "pos: "
		<< pRobot->getPosition().x << ", "
		<< pRobot->getPosition().y << "  ";
	MoveCursorToXY(0, 1);
	std::cout << std::setprecision(2) << std::fixed
		<< "vel: "
		<< pRobot->getVelocity().x << ", "
		<< pRobot->getVelocity().y << "  ";
	MoveCursorToXY(0, 2);
	std::cout << pRobot->getElapsedTime() << " seconds";
}
