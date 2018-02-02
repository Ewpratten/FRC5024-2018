#include "Robot.h"
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"

/**
 *
 */

void Robot::RobotInit()
{
	m_chooser.AddDefault("Default Auto", &m_defaultAuto);
	m_chooser.AddObject("My Auto", &m_myAuto);
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 *
 */

void Robot::DisabledInit() {}

/**
 *
 */

void Robot::DisabledPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

/**
 *
 */

void Robot::AutonomousInit()
{
	std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
	if (autoSelected == "My Auto")
	{
		m_autonomousCommand = &m_myAuto;
	} else {
		m_autonomousCommand = &m_defaultAuto;
	}

	m_autonomousCommand = m_chooser.GetSelected();

	if (m_autonomousCommand != nullptr)
	{
		m_autonomousCommand->Start();
	}
}

/**
 *
 */

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

/**
 *
 */

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autonomousCommand != nullptr) {
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

/**
 *
 */

void Robot::TeleopPeriodic() { frc::Scheduler::GetInstance()->Run(); }

/**
 *
 */

void Robot::TestPeriodic() {}

/**
 *
 */

START_ROBOT_CLASS(Robot)
