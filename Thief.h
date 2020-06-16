/*
 * Thief.h
 *
 *  Created on: Dec 25, 2018
 *      Author: ise
 */

#ifndef THIEF_H_
#define THIEF_H_
#include "Hero.h"
class Thief:public Hero{
public:
	Thief();
	Thief(string name);
	//Thief(int gold,int dailyGold, int SPAbility,int isHeroAlive, int numOfZ, int numOfA, int numOfV,int numOfW, int numOfBD);
	virtual void SpecialAbility(Hero &other);
	virtual ~Thief();
};




#endif /* THIEF_H_ */
