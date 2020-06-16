/*
 * Creature.h
 *
 *  Created on: Dec 23, 2018
 *      Author: ise
 */

#ifndef CREATURE_H_
#define CREATURE_H_
#include <string>
#include <iostream>
using namespace std;
class Creature{
protected:
	int attack;
	int defense;
	int cost;
	string name;
	int amount;

public:
	Creature();

	virtual void specialAbility(Creature &other)=0;
	virtual void Fight(Creature &other)=0;
	virtual void toAttack (Creature& other);
	void display();
	void setAmount(int toAdd);
	void setDefence(int toAdd);
	int getAmount();
	int getCost();
	string getName();
	int getAttack();
	int getDefence();
	virtual ~Creature();

	friend class Hero;

};



#endif /* CREATURE_H_ */
