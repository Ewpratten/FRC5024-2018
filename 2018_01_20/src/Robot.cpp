#include "Robot.h"

/**
 *
 */

const int LEFT_FRONT_MOTOR_ID = 4;
const int LEFT_REAR_MOTOR_ID = 3;
const int RIGHT_FRONT_MOTOR_ID = 1;
const int RIGHT_REAR_MOTOR_ID = 2;

const int CLIMB_MOTOR_ID = 7;

const int DRIVE_JOYSTICK_PORT_ID = 0;

Robot::Robot()
{
	this->m_pLeftFrontMotor = new WPI_TalonSRX(LEFT_FRONT_MOTOR_ID);
	this->m_pLeftRearMotor = new WPI_TalonSRX(LEFT_REAR_MOTOR_ID);
	this->m_pLeftSpeedController = new SpeedControllerGroup(*m_pLeftFrontMotor, *m_pLeftRearMotor);

	this->m_pRightFrontMotor = new WPI_TalonSRX(RIGHT_FRONT_MOTOR_ID);
	this->m_pRightRearMotor = new WPI_TalonSRX(RIGHT_REAR_MOTOR_ID);
	this->m_pRightSpeedController = new SpeedControllerGroup(*m_pRightFrontMotor, *m_pRightRearMotor);

	this->m_pRobotDrive = new DifferentialDrive(*m_pLeftSpeedController, *m_pRightSpeedController);

	this->m_pClimbMotor = new WPI_TalonSRX(CLIMB_MOTOR_ID);

	this->m_pXboxController = new XboxController(DRIVE_JOYSTICK_PORT_ID);
}

Robot::~Robot()
{
	delete this->m_pXboxController;
	delete this->m_pClimbMotor;
	delete this->m_pRobotDrive;
	delete this->m_pRightSpeedController;
	delete this->m_pLeftSpeedController;
	delete this->m_pLeftFrontMotor;
	delete this->m_pLeftRearMotor;
	delete this->m_pRightFrontMotor;
	delete this->m_pRightRearMotor;
}

void Robot::TeleopPeriodic()
{
	double climbSpeed = (this->m_pXboxController->GetYButton()) ? 1.0 : 0.0;
	m_pClimbMotor->Set(climbSpeed);

	double forwardSpeed = this->m_pXboxController->GetY(XboxController::kLeftHand);
	double turnAngle = this->m_pXboxController->GetX(XboxController::kLeftHand);
	this->m_pRobotDrive->ArcadeDrive(forwardSpeed, turnAngle);
}

START_ROBOT_CLASS(Robot)
