/*
 * RecordFileCommand.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: michael
 */

#include "RecordFileCommand.h"

RecordFileCommand::RecordFileCommand(Macro* m, std::string f) : RecordCommand (m) {
	// TODO Auto-generated constructor stub
	filename = f;
}
void RecordFileCommand::End() {
	macro->WriteFile(filename);
}

