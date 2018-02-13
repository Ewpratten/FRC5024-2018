#include <Commands/GripperTest.h>
#include <math.h>
#include "../RobotMap.h"

/**
 *
 */

GripperTest::GripperTest()
{
	std::cout << "[Gripper Test] Constructed" << std::endl;

	if (CommandBase::pIntake != nullptr)
	{
		Requires(CommandBase::pIntake);
	}
	else
	{
		std::cout << "[Gripper Test] driveTrain is null!" << std::endl;
	}

	return;
}

/**
 *
 */

void GripperTest::Initialize()
{
	std::cout << "[GripperTest] Initialized" << std::endl;

	return;
}

/**
 *
 */


void GripperTest::Execute()
{
	// grab

	typedef enum _DriveMode { Grab, Release } DriveMode;

	DriveMode mode = Grab;
	bool current, prev;
	prev = current = false;
	// Check the mode toggle button
	current = CommandBase::pOI->GetJoystickOperator()->GetBButton();
	if (mode == Grab) {
		int direction = 1;
		if (current && !prev){ mode = Release; }
	}
	else if (mode == Release) {
		int direction = -1;
	    if (current && !prev){ mode = Grab; }
	}
	prev = current;

	// I am using a temp function. someone should change this
	// blah(direction);
	// belts
	double forwardSpeed = CommandBase::pOI->GetJoystickOperator()->GetY(XboxController::kLeftHand);

	if (fabs(forwardSpeed) <= XBOX_DEADZONE_LEFT_JOY)
	{
		forwardSpeed = 0.0;
	}

	CommandBase::pIntake-> SetMotorSpeed(forwardSpeed,forwardSpeed);

	return;

}

/**
 *
 */

bool GripperTest::IsFinished()
{
	return false;
}

/**
 *
 */

void GripperTest::End()
{
	return;
}

/**
 *
 */

void GripperTest::Interrupted()
{
	return;
}
