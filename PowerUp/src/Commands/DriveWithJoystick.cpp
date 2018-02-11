#include "DriveWithJoystick.h"
#include <math.h>
#include "../RobotMap.h"

/**
 *
 */

DriveWithJoystick::DriveWithJoystick()
{
	std::cout << "[DriveWithJoystick] Constructed" << std::endl;

	if (CommandBase::pDriveTrain != nullptr)
	{
		Requires(CommandBase::pDriveTrain);
	}
	else
	{
		std::cout << "[DriveWithJoystick] driveTrain is null!" << std::endl;
	}

	return;
}

/**
 *
 */

void DriveWithJoystick::Initialize()
{
	std::cout << "[DriveWithJoystick] Initialized" << std::endl;

	return;
}

/**
 *
 */

void DriveWithJoystick::Execute()
{
	// Set SlowMode
	double slowMode = 1.0;
	if(CommandBase::pOI->GetJoystickDrive()->GetAButton()){slowMode = 0.55;}

	// Set Control Direction
	double controlDirectionMode = 1.0;
	if(CommandBase::pOI->GetJoystickDrive()->GetBButton()){controlDirectionMode = -1.0;}

	// Set ForwardSpeed and TurnAngle based on joystick position
	double forwardSpeed = CommandBase::pOI->GetJoystickDrive()->GetY(XboxController::kLeftHand);
	double turnAngle = CommandBase::pOI->GetJoystickDrive()->GetX(XboxController::kLeftHand);

	// Set DeadZone for X and Y of Left joystick on controller 1
	if (fabs(forwardSpeed) <= XBOX_DEADZONE_LEFT_JOY){ forwardSpeed = 0.0;}
	if (fabs(turnAngle) <= XBOX_DEADZONE_LEFT_JOY){ turnAngle = 0.0;}

	// Multiply ForwardSpeed and TurnAngle with others to set speed and direction
	forwardSpeed = forwardSpeed * controlDirectionMode * slowMode;
	turnAngle = turnAngle * slowMode;

	CommandBase::pDriveTrain->ArcadeDrive(forwardSpeed, turnAngle); //Drive the robot!

	return;
}

/**
 *
 */

bool DriveWithJoystick::IsFinished()
{
	return false;
}

/**
 *
 */

void DriveWithJoystick::End()
{
	return;
}

/**
 *
 */

void DriveWithJoystick::Interrupted()
{
	return;
}
