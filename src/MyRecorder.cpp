/*
 * MyRecorder.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: michael
 */

#include "MyRecorder.h"

MyRecorder::MyRecorder() {
	this->AddDevice("Left Front",RobotMap::chassisLeftFrontCtrl);
	this->AddDevice("Left Rear",RobotMap::chassisLeftRearCtrl);
	this->AddDevice("Right Front",RobotMap::chassisRightFrontCtrl);
	this->AddDevice("Right Rear", RobotMap::chassisRightRearCtrl);
	this->AddDevice("Winch", RobotMap::lifterWinch);
	this->AddDevice(new NewSol("Arm"));
	this->AddSubsystem(Robot::chassis);
	this->AddSubsystem(Robot::grabber);
	this->AddSubsystem(Robot::lifter);
}

