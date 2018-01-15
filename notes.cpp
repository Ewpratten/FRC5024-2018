//new drive program
//file>>new project>> C++ example>>arcade drive>> (give it a new name)
//src > robot.cpp
// change " to < or > in include
// dont touch libs
// include <ctre/Phoenix.h>
// make a robot.h file
#include "robot.h"
// move all code except start_robot_class(robot) to robot.h
// move teleop periotic to robot.cpp at top
// in robot.h remove everything in curly brackets of teleop periotic; replace cbrackets with ";"
// robot.cpp robot::TeleopPeriotic() (add Robot::)
// in robot.h (header guard) :
#ifndef _Robot_HG_
#define _Robot_HG_
