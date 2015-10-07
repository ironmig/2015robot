/*
 * MyRecorder.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: michael
 */

#include "MyRecorder.h"

MyRecorder::MyRecorder() {
	AddDevice("Left Front",RobotMap::chassisLeftFrontCtrl);
	AddDevice("Left Rear",RobotMap::chassisLeftRearCtrl);
	AddDevice("Right Front",RobotMap::chassisRightFrontCtrl);
	AddDevice("Right Rear", RobotMap::chassisRightRearCtrl);
	AddDevice("Winch", RobotMap::lifterWinch);
	AddDevice(new NewSol("Arm"));
	AddSubsystem(Robot::chassis);
	AddSubsystem(Robot::grabber);
	AddSubsystem(Robot::lifter);
}

