/*
 * PlayBackCommand.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: kma1660
 */

#include "PlayBackCommand.h"

PlayBackCommand::PlayBackCommand(Macro* m) {
	macro = m;
	for(std::vector<Subsystem*>::iterator dev = m->subsystems.begin(); dev != m->subsystems.end(); ++dev) {
		Requires(*dev);
	}
}
void PlayBackCommand::Initialize() {
	macro->PlayReset();
}

void PlayBackCommand::Execute() {
	macro->PlayBack();
}

bool PlayBackCommand::IsFinished() {
	return macro->IsFinished();
}

void PlayBackCommand::End() {
	macro->PlayReset();
}
void PlayBackCommand::Interrupted() {
	End();
}
