#include "DriveTrain.h"
#include "../Commands/DriveWithJoystick.h"

/**
 *
 */

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain")
{
	pLeftFrontMotor = new WPI_TalonSRX(LEFT_FRONT_MOTOR_ID);
	pLeftRearMotor = new WPI_TalonSRX(LEFT_REAR_MOTOR_ID);
	pLeftSpeedController = new SpeedControllerGroup(*pLeftFrontMotor, *pLeftRearMotor);

	pRightFrontMotor = new WPI_TalonSRX(RIGHT_FRONT_MOTOR_ID);
	pRightRearMotor = new WPI_TalonSRX(RIGHT_REAR_MOTOR_ID);
	pRightSpeedController = new SpeedControllerGroup(*pRightFrontMotor, *pRightRearMotor);

	pRobotDrive = new DifferentialDrive(*pLeftSpeedController, *pRightSpeedController);
}

/**
 *
 */

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

/**
 *
 */

int DriveTrain::GetLeftEncoderValue()
{
	double data = 0.0; // should be motor position from the enoder
	double equation = 2.0 * 3.1415 * WHEEL_RADIUS;

	return data * equation;
}

/**
 *
 */

int DriveTrain::GetRightEncoderValue()
{
	double data = 0.0; // should be motor position from the enoder
	double equation = 2.0 * 3.1415 * WHEEL_RADIUS;

	return data * equation;
}

// Put methods for controlling this subsystem here.
// Call these from Commands.

void DriveTrain::Drive(XboxController* joystick)
{
	double forwardSpeed = joystick->GetY(XboxController::kLeftHand);
	double turnAngle = joystick->GetX(XboxController::kLeftHand);

	pRobotDrive->ArcadeDrive(forwardSpeed, turnAngle);
}
