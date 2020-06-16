#include "Archer.h"

Archer::Archer(){
	this->attack=5;
	this->defense=4;
	this->cost=90;
	this->amount=0;
	this->name="Archer";
}



void Archer::specialAbility(Creature &other){
	if(other.getName()== "Black_Dragon")
		 this->attack=this->attack*1.2;
	else
		 this->attack;
}


void Archer::Fight(Creature &other) {
	int oldAttack=this->attack;
	specialAbility(other);
	this->toAttack(other);
	if(other.getName()== "Black_Dragon")
	{
		this->attack=oldAttack;
	}
}








