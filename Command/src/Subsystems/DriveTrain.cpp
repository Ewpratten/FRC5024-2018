#include "DriveTrain.h"

DriveTrain::DriveTrain() : frc::Subsystem("DriveTrain") {
	// Store value of WPI_TalonSRX(<ID>); in variable for left motors
	this->m_pLeftFrontMotor = new WPI_TalonSRX(LEFT_FRONT_MOTOR_ID);	// Right Front
	this->m_pLeftRearMotor = new WPI_TalonSRX(LEFT_REAR_MOTOR_ID);		// Right Back
	
	// Store value of WPI_TalonSRX(<ID>); in variable for right motors
	this->m_pRightFrontMotor = new WPI_TalonSRX(RIGHT_FRONT_MOTOR_ID);	// Left Front
	this->m_pRightRearMotor = new WPI_TalonSRX(RIGHT_REAR_MOTOR_ID);		// Left Back
	
	// Store speed controller data for configuring DifferentialDrive();
	this->m_pLeftSpeedController = new SpeedControllerGroup(*m_pLeftFrontMotor, *m_pLeftRearMotor);			// Left Controller
	this->m_pRightSpeedController = new SpeedControllerGroup(*m_pRightFrontMotor, *m_pRightRearMotor);	// Right Controller
	
	// Set RobotDrive using left and right speed controllers
	this->m_pRobotDrive = new DifferentialDrive(*m_pLeftSpeedController, *m_pRightSpeedController);
}

DriveTrain::~DriveTrain()
{
	// Deconstruct DriveTrain()
	delete this->m_pRobotDrive;
	delete this->m_pRightSpeedController;
	delete this->m_pLeftSpeedController;
	delete this->m_pLeftFrontMotor;
	delete this->m_pLeftRearMotor;
	delete this->m_pRightFrontMotor;
	delete this->m_pRightRearMotor;
}