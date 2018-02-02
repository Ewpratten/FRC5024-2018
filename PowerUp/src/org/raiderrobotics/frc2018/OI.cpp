#include "OI.h"
#include "RobotMap.h"

/**
 *
 */

OI::OI()
{
	joystick = new XboxController(XBOX_CONTROLLER_DRIVE_PORT);
}

/**
 *
 */

frc::XboxController* OI::GetJoystick()
{
	return joystick;
}
