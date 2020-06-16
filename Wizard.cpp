#include "Wizard.h"


Wizard::Wizard(){
	this->attack=8;
	this->defense=2;
	this->cost=150;
	this->amount=0;
	this->name="Wizard";
}

void Wizard::specialAbility(Creature &other){
	return;
}





void Wizard::Fight(Creature& other) {
	//int attacker =specialAbility(other);
	this->toAttack(other);
//	if(other.getName()== "Wizard"){
	//	this->defense=this->defense/2;
	//}

}





