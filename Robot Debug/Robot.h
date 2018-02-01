// If NOT defined, define _ROBOT_HG_
#ifndef _ROBOT_HG_
#define _ROBOT_HG_

// Include FRC libs
#include <SmartDashboard/SmartDashboard.h>
#include <IterativeRobot.h>
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>
#include <XboxController.h>
#include <iostream>

// Main object
class Robot : public frc::IterativeRobot
{
public:
	Robot();	// Run Robot()
	~Robot();	// Deconstruct Robot()
	void TeleopPeriodic();	// Run TELEOP code

private:
	// Set pointers to talons
	WPI_TalonSRX* m_pLeftFrontMotor;	// Left Front
	WPI_TalonSRX* m_pLeftRearMotor;		// Left Back
	WPI_TalonSRX* m_pRightFrontMotor;	// Right Front
	WPI_TalonSRX* m_pRightRearMotor;	// Right Back
	WPI_TalonSRX* m_pClimbMotor;			// Climb
	
	// Set pointers to speed controllers
	frc::SpeedControllerGroup* m_pLeftSpeedController;	// Left
	frc::SpeedControllerGroup* m_pRightSpeedController;	// Right

	// Set pointer to drive
	frc::DifferentialDrive* m_pRobotDrive;

	// Set pointer to Xbox controller
	frc::XboxController* m_pXboxController;
};

#endif // End the ifndef statement
