#ifndef _DRIVETRAIN_HG_
#define _DRIVETRAIN_HG_

#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <SpeedControllerGroup.h>
#include <Drive/DifferentialDrive.h>
#include "../RobotMap.h"

/**
 *
 */

class DriveTrain: public frc::Subsystem
{
public:
	DriveTrain();
	void InitDefaultCommand() override;
	void Drive(XboxController* joystick);
	int GetRightEncoderValue();
	int GetLeftEncoderValue();

private:
	WPI_TalonSRX* pLeftFrontMotor;
	WPI_TalonSRX* pLeftRearMotor;
	WPI_TalonSRX* pRightFrontMotor;
	WPI_TalonSRX* pRightRearMotor;

	frc::SpeedControllerGroup* pLeftSpeedController;
	frc::SpeedControllerGroup* pRightSpeedController;

	frc::DifferentialDrive* pRobotDrive;
};

#endif
