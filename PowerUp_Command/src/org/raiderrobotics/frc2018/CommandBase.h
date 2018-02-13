#ifndef _COMMANDBASE_HG_
#define _COMMANDBASE_HG_

#include <iostream>
#include <WPILib.h>
#include "Commands/Command.h"
#include "OI.h"
#include "Subsystems/DriveTrain.h"

/**
 *
 */

class CommandBase: public frc::Command
{
public:
	CommandBase();
	CommandBase(char const *name);
	static void init();
	static OI *oi;
	static DriveTrain *driveTrain;
};

#endif
