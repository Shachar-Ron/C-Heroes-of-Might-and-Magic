/*
 * BlackDragon.h
 *
 *  Created on: Dec 24, 2018
 *      Author: ise
 */

#ifndef BLACKDRAGON_H_
#define BLACKDRAGON_H_
#include "Creature.h"

class BlackDragon:public Creature{
public:
	BlackDragon();
	virtual void specialAbility(Creature &other);
	virtual void Fight(Creature &other);
	virtual ~BlackDragon(){};
};

#endif /* BLACKDRAGON_H_ */
