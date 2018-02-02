#include "Robot.h"	// Include Robot Lib

// Set ESC IDs for left motors
const int LEFT_FRONT_MOTOR_ID = 4;	// Left Front
const int LEFT_REAR_MOTOR_ID = 3;		// Left Back

// Set ESC IDs for right motors
const int RIGHT_FRONT_MOTOR_ID = 1;	// Right Front
const int RIGHT_REAR_MOTOR_ID = 2;	// Right Back

// Set controller port to listen from
const int DRIVE_JOYSTICK_PORT_ID = 0;

Robot::Robot()
{
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
	
	// Set XboxController(); to read from controller port 0
	this->m_pXboxController = new XboxController(DRIVE_JOYSTICK_PORT_ID);
	
}

Robot::~Robot()
{
	// Deconstruct Robot()
	delete this->m_pXboxController;
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
	// halfSpeed
	double SlowMode = (this->m_pXboxController->GetAButton()) ? 0.5 : 1;
	
	// Swap control orientation
	double ControlDirectionMode_Y = (this->m_pXboxController->GetBButton()) ? 1 : -1;	// If B pressed, ControlDirectionMode_Y = 1 (Setting to one is used to invert forwardSpeed)
	double ControlDirectionMode_X = (this->m_pXboxController->GetBButton()) ? -1 : 1;	// If B pressed, ControlDirectionMode_X = -1 (Setting to -one is used to invert turnAngle)
	
	// Set parameters for use by ArcadeDrive();
	double forwardSpeed = ((this->m_pXboxController->GetY(XboxController::kLeftHand))*ControlDirectionMode_Y)*SlowMode;	// Set speed from Y value of joystick
	double turnAngle = ((this->m_pXboxController->GetX(XboxController::kLeftHand))*ControlDirectionMode_X)*SlowMode;		// Set turn angle from X value of joystick
	
	// Drive the robot!
	this->m_pRobotDrive->ArcadeDrive(forwardSpeed, turnAngle);
}
// Don't mess with this
START_ROBOT_CLASS(Robot)
