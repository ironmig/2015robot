/*
 * NewSol.h
 *
 *  Created on: Apr 22, 2015
 *      Author: Michael
 */

#ifndef SRC_NEWSOL_H_
#define SRC_NEWSOL_H_

#include "Robot.h"
#include "RiptideRecorder/Device.h"
class NewSol : public Device{
public:
	NewSol(std::string x);
	virtual float get();
	virtual void set(float x);
private:

};

#endif /* SRC_NEWSOL_H_ */
