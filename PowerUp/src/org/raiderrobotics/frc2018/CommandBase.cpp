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
	oi = new OI();
	driveTrain = new DriveTrain();
}
