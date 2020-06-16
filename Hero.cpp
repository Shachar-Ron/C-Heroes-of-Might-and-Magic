#include "Hero.h"
#include <string>


const int Hero::MAX_GOLD=2500;


Hero::Hero(){
	this->name="";
	this->type="";
	this->gold=750;
	this->listOfCreature=new Creature*[5];
	listOfCreature[0] = new Zombie();
	listOfCreature[1] = new Archer();
	listOfCreature[2] = new Vampire();
	listOfCreature[3] = new Wizard();
	listOfCreature[4] = new BlackDragon();
	this->dailyGold=false;
	this->SPAbility=false;
	this->isHeroAlive=true;
};





int Hero::getNumOfCreatures(int i){
	return listOfCreature[i]->getAmount();
}




bool Hero::buyCreatures(){

	int sumOfHero;
	int choise;

	cout<<"1. Buy Zombies."<<endl;
	cout<<"2. Buy Archers."<<endl;
	cout<<"3. Buy Vampire."<<endl;
	cout<<"4. Buy Wizard."<<endl;
	cout<<"5. Buy Black Dragon."<<endl;
	cin>>choise;


	switch(choise){
//Buy Zombies
	case(1):{
		//print the details.
		this->listOfCreature[0]->display();

		cin>>sumOfHero;

		int cost = this->listOfCreature[0]->getCost();
		if( (cost* sumOfHero) > this->gold)
		{
			return false;
		}
		else
		{
			this->gold = this->gold - (sumOfHero * cost);
			int temp=this->listOfCreature[0]->getAmount();
			this->listOfCreature[0]->setAmount(temp+sumOfHero);
		}
		break;
	}


//Buy Archers
	case(2):{
		//print the details.
		this->listOfCreature[1]->display();

		cin>>sumOfHero;

		int cost = this->listOfCreature[1]->getCost();
		if( (cost* sumOfHero) > this->gold)
		{
			return false;
		}
		else
		{
			this->gold = this->gold - (sumOfHero * cost);
			int temp=this->listOfCreature[1]->getAmount();
			this->listOfCreature[1]->setAmount(temp+sumOfHero);
		}
		break;
	}


//Buy Vampire
	case(3):{
		//print the details.
		this->listOfCreature[2]->display();

		cin>>sumOfHero;

		int cost = this->listOfCreature[2]->getCost();
		if( (cost* sumOfHero) > this->gold)
		{
			return false;
		}
		else
		{
			this->gold = this->gold - (sumOfHero * cost);
			int temp=this->listOfCreature[2]->getAmount();
			this->listOfCreature[2]->setAmount(temp+sumOfHero);
		}
		break;
	}
//Buy Wizard
	case(4):{
		//print the details.
		this->listOfCreature[3]->display();

		cin>>sumOfHero;

		int cost = this->listOfCreature[3]->getCost();
		if( (cost* sumOfHero) > this->gold)
		{
			return false;
		}
		else
		{
			this->gold = this->gold - (sumOfHero * cost);
			int temp=this->listOfCreature[3]->getAmount();
			this->listOfCreature[3]->setAmount(temp+sumOfHero);
		}
		break;
	}
// Buy Black Dragon.
	case(5):{
		//print the details.
		this->listOfCreature[4]->display();

		cin>>sumOfHero;

		int cost = this->listOfCreature[4]->getCost();
		if( (cost* sumOfHero) > this->gold)
		{
			return false;
		}
		else
		{
			this->gold = this->gold - (sumOfHero * cost);
			int temp=this->listOfCreature[1]->getAmount();
			this->listOfCreature[4]->setAmount(temp+sumOfHero);
		}
		break;
	}

	}//switch
	return true;
}




int Hero::getGold()
{
	return this->gold;
}
void Hero::addGold(int toAdd)
{
	int tempSumGold=this->gold;
	if(tempSumGold + toAdd > 2500)
	{
		this->gold = 2500;
	}
	else
	{
		this->gold = tempSumGold + toAdd;
	}
}


void Hero::Display()
{
	cout<<this->name<<" "<<this->type<<":"<<endl;

	if(listOfCreature[4]->getAmount()>0)
	{
		cout<<this->listOfCreature[4]->amount<<" "<<this->listOfCreature[4]->name<<" ";
	}
	if(listOfCreature[3]->getAmount()>0)
	{
		cout<<this->listOfCreature[3]->amount<<" "<<this->listOfCreature[3]->name<<" ";
	}
	if(listOfCreature[1]->getAmount()>0)
	{
		cout<<this->listOfCreature[1]->amount<<" "<<this->listOfCreature[1]->name<<" ";
	}
	if(listOfCreature[2]->getAmount()>0)
	{
		cout<<this->listOfCreature[2]->amount<<" "<<this->listOfCreature[2]->name<<" ";
	}
	if(listOfCreature[0]->getAmount()>0)
	{
		cout<<this->listOfCreature[0]->amount<<" "<<this->listOfCreature[0]->name<<" ";
	}
	cout<<"\n";

}




void Hero::printHero()
{
	cout<<this->name<<" "<<this->type<<":"<<endl;
	cout<<this->gold<<" "<<"gold"<<endl;
	bool flag=false;

	if(listOfCreature[4]->getAmount()>0)
	{
		cout<<this->listOfCreature[4]->amount<<" "<<this->listOfCreature[4]->name<<" ";
		flag=true;
	}
	if(listOfCreature[3]->getAmount()>0)
	{
		cout<<this->listOfCreature[3]->amount<<" "<<this->listOfCreature[3]->name<<" ";
		flag=true;
	}
	if(listOfCreature[1]->getAmount()>0)
	{
		cout<<this->listOfCreature[1]->amount<<" "<<this->listOfCreature[1]->name<<" ";
		flag=true;
	}
	if(listOfCreature[2]->getAmount()>0)
	{
		cout<<this->listOfCreature[2]->amount<<" "<<this->listOfCreature[2]->name<<" ";
		flag=true;
	}
	if(listOfCreature[0]->getAmount()>0)
	{
		cout<<this->listOfCreature[0]->amount<<" "<<this->listOfCreature[0]->name<<" ";
		flag=true;
	}
	if(flag==true)
	{
		cout<<"\n";
	}


}

string Hero::getName(){
	return this->name;
}

void Hero::setName(string name){
	this->name=name;
}


string Hero::getType(){
	return this->type;
}

void Hero::setType(string type){
	this->type=type;
}


bool Hero:: getDailyGold()
{
	return this->dailyGold;
}

void Hero::changeDailyGold()
{
	if(this->dailyGold==false)
	{
		this->dailyGold=true;
	}
	else
	{
		this->dailyGold=false;
	}
}

bool Hero:: getSAbility()
{
	return this->SPAbility;
}

void Hero:: changeSAbility()
{
	if(this->SPAbility==false)
	{
		this->SPAbility=true;
	}
	else
	{
		this->SPAbility=false;
	}
}


bool Hero::getisHeroAlive()
{
	return this->isHeroAlive;
}

void Hero::changeisHeroAlive()
{
	if(this->isHeroAlive==false)
	{
		this->isHeroAlive=true;
	}
	else
	{
		this->isHeroAlive=false;
	}
}



void Hero::attack(Hero &other, int indexOfCretureAttack,int indexOfCretureDefence)
{
	if(this->listOfCreature[indexOfCretureAttack]->getAmount()==0 ||other.listOfCreature[indexOfCretureDefence]->getAmount()==0)
	{
		throw creatureNotExists();
	}
	this->listOfCreature[indexOfCretureAttack]->Fight(*(other.listOfCreature[indexOfCretureDefence]));

	bool isA=false;
	for(int i=0;i<5;i++)
	{
		int tempAmount=other.listOfCreature[i]->getAmount();
		if(tempAmount>0)
		{
			isA= true;//there is creture
		}
	}
	if(isA==false)
	{
		other.isHeroAlive=false;
	}
}



int Hero:: checkCretureName(string name)
{
	if(name=="Zombie")
	{
		return 0;
	}
	else if(name=="Archer")
	{
		return 1;
	}
	else if(name=="Vampire")
	{
		return 2;
	}
	else if(name=="Wizard")
	{
		return 3;
	}
	else if(name=="Black_Dragon")
	{
		return 4;
	}
	else
	{
		return -1;
	}

}


void Hero::setGold(int i)
{
	this->gold=i;
}

void Hero::removeGold(int i)
{
	this->gold=this->gold-i;
}



void Hero::setdailyGold(int i)
{
	if(i==0)
	{
		this->dailyGold=false;
	}
	else
	{
		this->dailyGold=true;
	}

}
void Hero::setSPAbility(int i)
{
	if(i==0)
	{
		this->SPAbility=false;
	}
	else
	{
		this->SPAbility=true;
	}

}
void Hero::setisHeroAlive(int i)
{
	if(i==0)
	{
		this->isHeroAlive=false;
	}
	else
	{
		this->isHeroAlive=true;
	}

}
void Hero::setnumOfZombie(int i)
{
	this->listOfCreature[0]->setAmount(i);
}
void Hero::setnumOfArcher(int i)
{
	this->listOfCreature[1]->setAmount(i);
}
void Hero::setnumOfVampire(int i)
{
	this->listOfCreature[2]->setAmount(i);
}
void Hero::setnumOfWizard(int i)
{
	this->listOfCreature[3]->setAmount(i);
}
void Hero::setnumOfBlackDragon(int i)
{
	this->listOfCreature[4]->setAmount(i);
}







bool Hero:: checkName(string name){

	if(name.length()<32)
	{
		int i;
		int total=name.length();
		for(i=0;i<total;i++)
		{
			int tempChar = (int)name[i];
			if(!(tempChar>=65 && tempChar<=90) && !(tempChar>=97 && tempChar<=122) && !(tempChar>=48 && tempChar<=57))
			{

				return false;

			}
		}
		return true;

	}

	return false;
}

Hero::~Hero()
{
/*
	delete this->listOfCreature[0];
	delete this->listOfCreature[1];
	delete this->listOfCreature[2];
	delete this->listOfCreature[3];
	delete this->listOfCreature[4];
	delete this->listOfCreature;
*/
}

