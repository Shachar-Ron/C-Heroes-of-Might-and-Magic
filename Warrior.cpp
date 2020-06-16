#include "Warrior.h"


Warrior::Warrior() {
	this->type = "Warrior";
}


Warrior::Warrior(string name){
	this->name = name;
	this->type = "Warrior";

}



void Warrior::SpecialAbility(Hero &other){
	this->addGold(50);
}




Warrior::~Warrior()
{

	delete this->listOfCreature[0];
	delete this->listOfCreature[1];
	delete this->listOfCreature[2];
	delete this->listOfCreature[3];
	delete this->listOfCreature[4];
	delete [] this->listOfCreature;

}
