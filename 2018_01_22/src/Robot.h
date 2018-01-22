#ifndef _ROBOT_HG_
#define _ROBOT_HG_

#include <IterativeRobot.h>
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>
#include <XboxController.h>

/**
 *
 */

class Robot : public frc::IterativeRobot
{
public:
	Robot();
	~Robot();
	void TeleopPeriodic();

private:
	WPI_TalonSRX* m_pLeftFrontMotor;
	WPI_TalonSRX* m_pLeftRearMotor;
	WPI_TalonSRX* m_pRightFrontMotor;
	WPI_TalonSRX* m_pRightRearMotor;

	frc::SpeedControllerGroup* m_pLeftSpeedController;
	frc::SpeedControllerGroup* m_pRightSpeedController;

	frc::DifferentialDrive* m_pRobotDrive;

	WPI_TalonSRX* m_pClimbMotor;

	frc::XboxController* m_pXboxController;
};

#endif
