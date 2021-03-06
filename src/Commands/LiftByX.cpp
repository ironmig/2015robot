// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "LiftByX.h"

LiftByX::LiftByX(int x) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::lifter);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	goal = 0;
	X = x;
	speed = 0;
}

// Called just before this Command runs the first time
void LiftByX::Initialize() {
	goal = Robot::lifter->Levels+X;
	if (Robot::lifter->Levels < goal) speed = -1; //if current level is less than goal level, go up
	else if (Robot::lifter->Levels > goal) speed=1;//if current level is great than goal level, go down
	else return this->Cancel(); //if already at that level, stop

	Robot::lifter->Set(speed);
}

// Called repeatedly when this Command is scheduled to run
void LiftByX::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LiftByX::IsFinished() {
	return Robot::lifter->Levels == goal;
}

// Called once after isFinished returns true
void LiftByX::End() {
	Robot::lifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftByX::Interrupted() {
	End();
}
