/*
 * Vampire.h
 *
 *  Created on: Dec 24, 2018
 *      Author: ise
 */

#ifndef VAMPIRE_H_
#define VAMPIRE_H_
#include "Creature.h"

class Vampire:public Creature{
public:
	Vampire();
	virtual void specialAbility(Creature &other);
	virtual void Fight(Creature &other);
	virtual ~Vampire(){};
};




#endif /* VAMPIRE_H_ */
