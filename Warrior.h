/*
 * Warrior.h
 *
 *  Created on: Dec 25, 2018
 *      Author: ise
 */

#ifndef WARRIOR_H_
#define WARRIOR_H_
#include "Hero.h"
class Warrior:public Hero{
public:
	Warrior();
	Warrior(string name);


	virtual void SpecialAbility(Hero &other);
	virtual ~Warrior();

};

#endif /* WARRIOR_H_ */

