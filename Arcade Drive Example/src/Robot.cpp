#include "Robot.h"

const int LEFT_MOTOR_ID = 0;
const int RIGHT_MOTOR_ID = 1;
const int DRIVE_JOYSTICK_PORT_ID = 0;

Robot::Robot()
{
	this-> m_pLeftMotor = new WPI_TalonSRX(LEFT_MOTOR_ID);
	this-> m_pRightMotor = new WPI_TalonSRX(RIGHT_MOTOR_ID);
	this-> m_pStick = new frc::Joystick(DRIVE_JOYSTICK_PORT_ID);

	this-> m_pRobotDrive = new frc::DifferentialDrive( *this-> m_pLeftMotor, *this-> m_pRightMotor);
	return;
}

Robot::~Robot()
{

	delete this-> m_pLeftMotor;
	delete this-> m_pRightMotor;
	delete this-> m_pStick;
	delete this-> m_pRobotDrive;
	return;
}


void Robot::TeleopPeriodic()
{
	// drive with arcade style
	double forwardSpeed = this->m_pStick->GetY();
	double turnAngle = this->m_pStick->GetY();
	this-> m_pRobotDrive->ArcadeDrive(forwardSpeed, turnAngle);
}

START_ROBOT_CLASS(Robot)
