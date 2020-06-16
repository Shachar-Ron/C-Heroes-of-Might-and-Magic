/*
 * Necromancer.h
 *
 *  Created on: Dec 25, 2018
 *      Author: ise
 */

#ifndef NECROMANCER_H_
#define NECROMANCER_H_
#include "Hero.h"
class Necromancer:public Hero{
public:

	Necromancer(){};
	Necromancer(string name);
	//Necromancer(int gold,int dailyGold, int SPAbility,int isHeroAlive, int numOfZ, int numOfA, int numOfV,int numOfW, int numOfBD);
	virtual void SpecialAbility(Hero &other);
	virtual ~Necromancer();
};




#endif /* NECROMANCER_H_ */
