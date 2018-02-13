#ifndef _ROBOT_HG_
#define _ROBOT_HG_

#include <iostream>
#include <WPILib.h>
#include "Commands/DriveWithJoystick.h"
#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"

/**
 *
 */

class Robot : public frc::TimedRobot
{
public:
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
	DriveWithJoystick m_driveWithJoystick;
	frc::SendableChooser<frc::Command*> m_chooser;

private:
};

#endif
