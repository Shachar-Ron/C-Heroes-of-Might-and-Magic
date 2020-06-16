#include "Vampire.h"


Vampire::Vampire(){
	this->attack=4;
	this->defense=4;
	this->cost=80;
	this->amount=0;
	this->name="Vampire";
}

void Vampire::specialAbility(Creature &other){
	return;
}

void Vampire::Fight(Creature& other) {
	this->toAttack(other);

}
