// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "Commands/GrabContainerAndBackup.h"
#include "Commands/AutoToteContainerStack.h"
#include "Commands/MoveForwardAndTurn.h"
#include "Commands/DoNothingAuto.h"

#include "Robot.h"

//#include "arm/include/OpenCV/opencv2/opencv.hpp"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Chassis* Robot::chassis = 0;
LedStrip* Robot::ledStrip = 0;
Grabber* Robot::grabber = 0;
Lifter* Robot::lifter = 0;
OI* Robot::oi = 0;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

Recorder* Robot::rec = NULL;
Macro* Robot::mac1 = NULL;
Macro* Robot::mac2 = NULL;
bool Robot::tele = NULL;

void Robot::RobotInit() {
	tele = false;

	RobotMap::init();


	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	chassis = new Chassis();
	ledStrip = new LedStrip();
	grabber = new Grabber();
	lifter = new Lifter();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS



	oi = new OI();
	lw = LiveWindow::GetInstance();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	//CameraServer::GetInstance()->StartAutomaticCapture("cam0");

	autonomousCommand = new GrabContainerAndBackup();

	rec = new MyRecorder();
	mac1 = rec->macro();
	mac2 = rec->macro();

	//Autonomous choosing
	autoChooser = new SendableChooser();
	autoChooser->AddDefault("Container or Tote", new GrabContainerAndBackup() );
	autoChooser->AddObject("Move Forward",new MoveForwardAndTurn()) ;
	autoChooser->AddObject("Stack", new AutoToteContainerStack());
	autoChooser->AddObject("Do Nothing (lame)", new DoNothingAuto());

	autoChooser->AddObject("Play Right Macro (1) ", mac1->NewPlayFileCommand("/home/lvuser/mac1.csv"));
	autoChooser->AddObject("Play Left Macro (2)", mac2->NewPlayFileCommand("/home/lvuser/mac2.csv"));


	SmartDashboard::PutData("Auto Program", autoChooser);

	SmartDashboard::PutBoolean("Bottom hit", false);
	SmartDashboard::PutBoolean("Stop at bottom",true);

}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit () {
	Scheduler::GetInstance()->RemoveAll();
	grabber->Stop();
	chassis->Stop();
	lifter->Stop();

	ledStrip->Set(0,1,1,0);
}
void Robot::DisabledPeriodic() {

}


void Robot::AutonomousInit() {
	tele = false;
	lifter->SetLightOff();
	ledStrip->Set(0,0,0,0);
	autonomousCommand = (Command*) autoChooser->GetSelected();
	//autonomousCommand  = new AutoToteContainerStack();
	autonomousCommand->Start();
}
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
void Robot::TeleopInit() {
	tele = true;
	lifter->SetLightOff();
	ledStrip->Set(0,0,1,0);
	if ( autonomousCommand->IsRunning() ) autonomousCommand->Cancel();

	grabber->airCompressor->Start();
	oi->driveWithJoysticks->Start();
	oi->lifterWithJoystick->Start();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	if (oi->getStickRight()->GetRawButton(9)) lifter->stopAtBottom = false;
	else if (oi->getStickRight()->GetRawButton(8)) lifter->stopAtBottom = true;

	SmartDashboard::PutBoolean("Bottom hit", lifter->BottomHit());
	SmartDashboard::PutBoolean("Stop at bottom",lifter->stopAtBottom);
}
void Robot::TestInit() {

}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);

