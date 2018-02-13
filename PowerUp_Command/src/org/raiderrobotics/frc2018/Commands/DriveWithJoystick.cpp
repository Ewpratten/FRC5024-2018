#include "DriveWithJoystick.h"

/**
 *
 */

DriveWithJoystick::DriveWithJoystick()
{
	std::cout << "[DriveWithJoystick] Constructed" << std::endl;

	Requires(CommandBase::driveTrain);
}

/**
 *
 */

void DriveWithJoystick::Initialize()
{
	std::cout << "[DriveWithJoystick] Initialized" << std::endl;
}

/**
 *
 */

void DriveWithJoystick::Execute()
{
	std::cout << "[DriveWithJoystick] Executing" << std::endl;

	CommandBase::driveTrain->Drive(CommandBase::oi->GetJoystick());
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

}

/**
 *
 */

void DriveWithJoystick::Interrupted()
{

}
