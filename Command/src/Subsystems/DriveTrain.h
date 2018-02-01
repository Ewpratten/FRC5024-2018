#ifndef _DRIVETRAIN_HG_ 	// If _DRIVETRAIN_HG_ is not defined,
#define _DRIVETRAIN_HG_		// Then define _DRIVETRAIN_HG_

#include <WPILib.h> 						// Include WPI Library
#include <ctre/Phoenix.h>				// Include Talon Lib
#include "../RobotMap.h"				// Include RobotMap
#include <Commands/Subsystem.h>	// Include Subsystem

class DriveTrai: public frc::Subsystem {
	public:
		DriveTrain();		// run DriveTrain();
		~DriveTrain();	// Deconstruct DriveTrain();
		
	private:
		// Set pointers to talons
		WPI_TalonSRX* m_pLeftFrontMotor;	// Left Front
		WPI_TalonSRX* m_pLeftRearMotor;		// Left Back
		WPI_TalonSRX* m_pRightFrontMotor;	// Right Front
		WPI_TalonSRX* m_pRightRearMotor;	// Right Back
		
		// Set pointers to speed controllers
		frc::SpeedControllerGroup* m_pLeftSpeedController;	// Left
		frc::SpeedControllerGroup* m_pRightSpeedController;	// Right
		
		// Set pointer to drive
		frc::DifferentialDrive* m_pRobotDrive;
};

#endif