

#ifndef HERO_H_
#define HERO_H_
#include <string>
#include <iostream>
#include "Creature.h"
#include "BlackDragon.h"
#include "Zombie.h"
#include "Vampire.h"
#include "Archer.h"
#include "Wizard.h"
#include "Exception.h"

#include <string>
using namespace std;
enum turns {player1,player2};

class Hero{
protected:
	string name;
	string type;
	int gold;
	bool dailyGold;
	bool SPAbility;
	bool isHeroAlive;
	Creature **listOfCreature;

	static const int MAX_GOLD;
public:


	Hero();
	bool buyCreatures();
	void addGold(int toAdd);
	void attack(Hero &other, int indexOfCretureAttack,int indexOfCretureDefence);

	int checkCretureName(string name);
	bool checkName(string name);

	void printHero();
	void Display();

	virtual void SpecialAbility(Hero &other)=0;

	void changeDailyGold();
	bool getDailyGold();
	void changeSAbility();
	bool getSAbility();
	bool getisHeroAlive();
	void changeisHeroAlive();


	int getNumOfCreatures(int i);


	int getGold();
	void removeGold(int i);
	string getName();
	void setName(string name);
	string getType();
	void setType(string type);
	virtual ~Hero();



	void setGold(int i);
	void setdailyGold(int i);
	void setSPAbility(int i);
	void setisHeroAlive(int i);
	void setnumOfZombie(int i);
	void setnumOfArcher(int i);
	void setnumOfVampire(int i);
	void setnumOfWizard(int i);
	void setnumOfBlackDragon(int i);



};






#endif /* HERO_H_ */
