#include "Necromancer.h"



Necromancer::Necromancer(string name){
	this->name = name;
	this->type = "Necromancer";

}




void Necromancer::SpecialAbility(Hero &other){
	listOfCreature[0]->setAmount(listOfCreature[0]->getAmount() +1 );
}

Necromancer::~Necromancer()
{


		delete this->listOfCreature[0];
		delete this->listOfCreature[1];
		delete this->listOfCreature[2];
		delete this->listOfCreature[3];
		delete this->listOfCreature[4];
		delete [] this->listOfCreature;


}




