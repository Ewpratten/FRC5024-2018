#ifndef _sPhysInfo_HG_
#define _sPhysInfo_HG_

// This represents the internal, discrete, 
//	instantaneous state of the robot 
//	(or any other rigid body)

#include "sPoint2D.h"

struct sPhysInfo
{
	sPoint2D position;
	sPoint2D velocity;
	sPoint2D accel;
};

#endif
