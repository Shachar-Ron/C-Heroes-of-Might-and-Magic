#include "Thief.h"


Thief::Thief() {

}

Thief::Thief(string name){
	this->name = name;
	this->type = "Thief";

}

void Thief::SpecialAbility(Hero &other){

	if(this->getGold()+70>2500)
	{
		int temp= 2500-this->getGold();

		this->setGold(2500);
		other.removeGold(temp);
	}

	else if(other.getGold() >= 70)
	{
		this->addGold(70);
		other.removeGold(70);
		/*
		if(this->gold - 70 < 0){
			this->gold = 0;
		}
		else
		{
			this->gold = this->gold - 70;
		}
		*/
	}
	else{
		int temp=other.getGold();
		this->addGold(temp);
		other.setGold(0);
		/*
		if(this->gold - 70 < 0){
			this->gold = 0;
		}
		else
		{
			this->gold = this->gold - 70;
		}
		*/
	}
}

Thief::~Thief()
{


		delete this->listOfCreature[0];
		delete this->listOfCreature[1];
		delete this->listOfCreature[2];
		delete this->listOfCreature[3];
		delete this->listOfCreature[4];
		delete [] this->listOfCreature;


}

