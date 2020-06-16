
#include "BlackDragon.h"

BlackDragon::BlackDragon(){
	this->attack=9;
	this->defense=10;
	this->cost=200;
	this->amount=0;
	this->name="Black_Dragon";
}

void BlackDragon::specialAbility(Creature &other){
	if(other.getName()== "Wizard")
		other.setDefence(other.getDefence()*2);
	//else
		 //other.getDefence();
}


void BlackDragon::Fight(Creature &other) {
	specialAbility(other);
	this->toAttack(other);
	if(other.getName()== "Wizard"){
		other.setDefence(other.getDefence()/2);
	}
}




