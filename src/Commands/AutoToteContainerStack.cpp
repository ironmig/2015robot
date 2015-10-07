// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoToteContainerStack.h"

AutoToteContainerStack::AutoToteContainerStack() {
	releasePause = 1;
	grabPause = 1;

	toContainerSpeed = -0.5;
	toContainerTime = 0.35;

	liftContainerSpeed = 1;
	liftContainerTime = 0.75;

	strafeToToteSpeed = -0.5;
	strafeToToteTime = 1.1;

	backupToToteSpeed = 0.5;
	backupToToteTime = 0.25;

	lowerToStackSpeed = -1;
	lowerToStackTime = 1.25;

	AddSequential(new Release()); //Release Arms
	AddSequential(new PauseX(releasePause));

	AddSequential(new DriveForTime(0,toContainerSpeed,0,toContainerTime)); //Drive To Container;

	AddSequential(new Grab()); //Grab container
	AddSequential(new PauseX(grabPause));

	AddSequential(new LiftForTime(liftContainerSpeed,liftContainerTime) ); //Raise arm over tote

	AddSequential(new DriveForTime(strafeToToteSpeed,0,0,strafeToToteTime)); //Strafe to tote

	AddSequential(new DriveForTime(0,backupToToteSpeed,0,backupToToteTime)); //Backup a bit

	AddSequential(new Release()); //Release Container onto tote
	AddSequential(new PauseX(releasePause));

	AddSequential(new LiftForTime(lowerToStackSpeed,lowerToStackTime)); //Lower arm to tote level

	AddSequential(new Grab()); //Grab whole stack
	AddSequential(new PauseX(grabPause));

	AddSequential(new DriveForTime(0,0.5,0,1.9));
	AddSequential(new DriveForTime(0,0,-0.5,1));
}