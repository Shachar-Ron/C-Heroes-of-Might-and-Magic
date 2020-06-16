/*
 * Zombie.h
 *
 *  Created on: Dec 23, 2018
 *      Author: ise
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_
#include "Creature.h"

class Zombie:public Creature{
public:
	Zombie();
	virtual void specialAbility(Creature &other);
	virtual void Fight(Creature &other);
	virtual ~Zombie(){};
};

#endif /* ZOMBIE_H_ */
