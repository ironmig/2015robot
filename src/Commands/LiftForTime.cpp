// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "LiftForTime.h"

LiftForTime::LiftForTime(float speed, float time) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::lifter);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Speed = speed;
	Time = time;
	timer = new Timer();
}

// Called just before this Command runs the first time
void LiftForTime::Initialize() {
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void LiftForTime::Execute() {
	Robot::lifter->Set(Speed);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftForTime::IsFinished() {
	return timer->Get()>=Time;
}

// Called once after isFinished returns true
void LiftForTime::End() {
	Robot::lifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftForTime::Interrupted() {

}