#ifndef _DRIVEWITHJOYSTICK_HG_
#define _DRIVEWITHJOYSTICK_HG_

#include <iostream>
#include <WPILib.h>
#include "../CommandBase.h"

/**
 *
 */

class DriveWithJoystick: public CommandBase
{
public:
	DriveWithJoystick();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif
