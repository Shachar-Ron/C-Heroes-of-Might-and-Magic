#include "Zombie.h"

Zombie::Zombie(){
	this->attack=2;
	this->defense=5;
	this->cost=50;
	this->amount=0;
	this->name="Zombie";
}


void Zombie::specialAbility(Creature &other){
	if(other.getName()== "Archer")
		  this->attack=this->attack*2;
	else
		 	return;
}



void Zombie::Fight(Creature &other) {

	specialAbility(other);
	this->toAttack(other);
	if(other.getName()== "Archer")
	{
		this->attack=this->attack/2;
	}

}




