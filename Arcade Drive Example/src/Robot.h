#ifndef _Robot_2018_01_15_
#define _Robot_2018_01_15_

#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <ctre/Phoenix.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */


class Robot : public frc::IterativeRobot
{
public:
	Robot();
	~Robot();
	void TeleopPeriodic();

private:

	WPI_TalonSRX* m_pLeftMotor;
	WPI_TalonSRX* m_pRightMotor;
	frc::DifferentialDrive* m_pRobotDrive;
	frc::Joystick* m_pStick;
};

#endif




