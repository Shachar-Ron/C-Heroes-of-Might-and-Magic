/*
 * Wizard.h
 *
 *  Created on: Dec 24, 2018
 *      Author: ise
 */

#ifndef WIZARD_H_
#define WIZARD_H_
#include "Creature.h"

class Wizard:public Creature{
public:
	Wizard();
	virtual void specialAbility(Creature &other);
	virtual void Fight(Creature &other);
	virtual ~Wizard(){};
};




#endif /* WIZARD_H_ */
