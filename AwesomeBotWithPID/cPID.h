#ifndef _PID_H_
#define _PID_H_

class cPIDImpl;
class cPID
{
public:
	// dt -  loop interval time
	// max - maximum value of manipulated variable
	// min - minimum value of manipulated variable
	// Kp -  proportional gain
	// Ki -  Integral gain
	// Kd -  derivative gain
	cPID(double dt, double max, double min, double Kp, double Ki, double Kd);
	~cPID();

	// Returns the manipulated variable given a setpoint and current process value
	double calculate(double setpoint, double pv);

private:
	cPIDImpl *pimpl;
};

#endif
