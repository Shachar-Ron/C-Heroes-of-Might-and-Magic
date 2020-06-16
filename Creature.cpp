#include "Creature.h"


Creature::Creature()
{
	this->attack=0;
	this->defense=0;
	this->cost=0;
	this->amount=0;
	this->name="";
}
void Creature::toAttack (Creature& other){


    int totalAmount= this->getAmount()*this->getAttack();
    int totalDefence = other.getAmount() * other.getDefence();
    if(totalAmount==totalDefence||totalAmount>totalDefence)
    {
    	other.setAmount(0);
    }
    else
    {
    	int	newAmount= (totalDefence-totalAmount);
        int newAmount2=newAmount/other.getDefence();
        if(newAmount2%other.getDefence()>0)
        {
            newAmount2++;
        }
        other.setAmount(newAmount2);
    }
}


void Creature::display(){
	cout<<"Attack level: "<<this->attack<<", "<<"Defense level: "<<this->defense<<endl;
}



void Creature::setAmount(int toAdd){
	this->amount=toAdd;
}
void Creature::setDefence(int toAdd){
	this->defense=toAdd;
}


string Creature::getName(){
	return this->name;
}
int Creature::getAmount(){
	return this->amount;
}
int Creature::getCost(){
	return this->cost;
}

int Creature::getAttack(){
	return this->attack;
}

int Creature::getDefence(){
	return this->defense;
}






Creature::~Creature(){

}



