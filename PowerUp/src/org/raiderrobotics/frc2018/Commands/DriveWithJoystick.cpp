#include "DriveWithJoystick.h"

/**
 *
 */

DriveWithJoystick::DriveWithJoystick()
{
	Requires(CommandBase::driveTrain);
}

/**
 *
 */

void DriveWithJoystick::Initialize()
{
}

/**
 *
 */

void DriveWithJoystick::Execute()
{
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
