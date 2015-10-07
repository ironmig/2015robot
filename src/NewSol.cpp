/*
 * NewSol.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: Michael
 */

#include "NewSol.h"

NewSol::NewSol(std::string x) : Device(x) {}
float NewSol::get() {
	switch (Robot::grabber->state) {
		case DoubleSolenoid::kForward :
			return 1;
			break;
		case DoubleSolenoid::kReverse :
			return -1;
			break;
		default:
			return 0;
	}
}
void NewSol::set(float x) {
	int y = x;
	switch (y) {
		case 1:
			Robot::grabber->Release();
			break;
		case -1:
			Robot::grabber->Grab();
			break;
		default:
			Robot::grabber->Stop();
	}
}

