#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"

/**
 *
 */

DriveTrain* CommandBase::driveTrain = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase() : Command()
{
}

/**
 *
 */

CommandBase::CommandBase(char const *name) : Command(name)
{
}

/**
 *
 */

void CommandBase::init()
{
	std::cout << "[CommandBase] Initialized" << std::endl;

	oi = new OI();
	driveTrain = new DriveTrain();
}
