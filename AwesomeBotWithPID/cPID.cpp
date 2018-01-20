#include <iostream>
#include <cmath>
#include "cPID.h"

using namespace std;

class cPIDImpl
{
public:
	cPIDImpl(double dt, double max, double min, double Kp, double Ki, double Kd);
	~cPIDImpl();
	double calculate(double setpoint, double pv);

private:
	double _dt;
	double _max;
	double _min;
	double _Kp;
	double _Ki;
	double _Kd;
	double _pre_error;
	double _integral;
};

cPID::cPID(double dt, double max, double min, double Kp, double Ki, double Kd)
{
	pimpl = new cPIDImpl(dt, max, min, Kp, Ki, Kd);
}

cPID::~cPID()
{
	delete pimpl;
}

double cPID::calculate(double setpoint, double pv)
{
	return pimpl->calculate(setpoint, pv);
}

/**
* Implementation
*/

cPIDImpl::cPIDImpl(double dt, double max, double min, double Kp, double Ki, double Kd) :
	_dt(dt),
	_max(max),
	_min(min),
	_Kp(Kp),
	_Ki(Ki),
	_Kd(Kd),
	_pre_error(0),
	_integral(0)
{
}

double cPIDImpl::calculate(double setpoint, double pv)
{
	double error = setpoint - pv;
	double Pout = _Kp * error;

	_integral += error * _dt;
	double Iout = _Ki * _integral;

	double derivative = (error - _pre_error) / _dt;
	double Dout = _Kd * derivative;

	double output = Pout + Iout + Dout;

	// Restrict to max/min
	if (output > _max)
		output = _max;
	else if (output < _min)
		output = _min;

	// Save error to previous error
	_pre_error = error;

	return output;
}

cPIDImpl::~cPIDImpl() {}
