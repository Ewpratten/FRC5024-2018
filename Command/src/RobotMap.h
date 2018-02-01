/*
The RobotMap is a mapping from the ports sensors and actuators are wired into
to a variable name. This provides flexibility changing wiring, makes checking
the wiring easier and significantly reduces the number of magic numbers
floating around.


For example to map the left and right motors, you could define the
following variables to use with your drivetrain subsystem.
constexpr int kLeftMotor = 1;
constexpr int kRightMotor = 2;

If you are using multiple modules, make sure to define both the port
number and the module. For example you with a rangefinder:
constexpr int kRangeFinderPort = 1;
constexpr int kRangeFinderModule = 1;
*/

#ifndef _ROBOTMAP_HG_	// If _ROBOTMAP_HG_ is not defined,
#define _ROBOTMAP_HG_	// Then define _ROBOTMAP_HG_

// Set ESC IDs for left motors
const int LEFT_FRONT_MOTOR_ID = 4;	// Left Front
const int LEFT_REAR_MOTOR_ID = 3;		// Left Back

// Set ESC IDs for right motors
const int RIGHT_FRONT_MOTOR_ID = 1;	// Right Front
const int RIGHT_REAR_MOTOR_ID = 2;	// Right Back