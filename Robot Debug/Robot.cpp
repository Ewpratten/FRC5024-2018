#include "Robot.h"	// Include Robot Lib

// Set ESC IDs for left motors
const int LEFT_FRONT_MOTOR_ID = 4;	// Left Front
const int LEFT_REAR_MOTOR_ID = 3;		// Left Back

// Set ESC IDs for right motors
const int RIGHT_FRONT_MOTOR_ID = 1;	// Right Front
const int RIGHT_REAR_MOTOR_ID = 2;	// Right Back

// Set ESC ID for climb motor
const int CLIMB_MOTOR_ID = 7;

// Set controller port to listen from
const int DRIVE_JOYSTICK_PORT_ID = 0;

Robot::Robot()
{
	// Store value of WPI_TalonSRX(<ID>); in variable for climb motor
	this->m_pClimbMotor = new WPI_TalonSRX(CLIMB_MOTOR_ID);
	
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
	
	// This stuff is for debugging and testing
	SmartDashboard::PutString("DB/String 5", *m_pLeftFrontMotor);						// What does WPI_TalonSRX(); do? print it to slot 5
	SmartDashboard::PutString("DB/String 6", *m_pLeftSpeedController);			// What does SpeedControllerGroup(); do? print it to slot 6
}

Robot::~Robot()
{
	// Deconstruct Robot()
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
	// Set climbSpeed to 100% if button Y is pressed, else, set to 0%
	double climbSpeed = (this->m_pXboxController->GetYButton()) ? 1.0 : 0.0;
	// Set motor speed to value of climbSpeed
	m_pClimbMotor->Set(climbSpeed);
	
	/*
	We should test the robot's capability to make precise turns at high turnAngle values.
	Then set a buffer at the ends (like set max value to 80%) to improve precision and agility of the robot
	*/
	// Set parameters for use by ArcadeDrive();
	double forwardSpeed = this->m_pXboxController->GetY(XboxController::kLeftHand);	// Set speed from Y value of joystick
	double turnAngle = this->m_pXboxController->GetX(XboxController::kLeftHand);		// Set turn angle from X value of joystick
	
	// Drive the robot!
	this->m_pRobotDrive->ArcadeDrive(forwardSpeed, turnAngle);
	
	// This stuff is for debugging and testing
	SmartDashboard::PutString("DB/String 0", forwardSpeed);		// print speed to slot 0
	SmartDashboard::PutString("DB/String 1", turnAngle);			// print turn angle to slot 1
	
}
// Don't mess with this
START_ROBOT_CLASS(Robot)