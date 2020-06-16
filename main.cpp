//8.1 00:00



#include "Hero.h"
#include "Warrior.h"
#include "Thief.h"
#include "Necromancer.h"
#include "Creature.h"
#include "Exception.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
using namespace std;







//void save_hero(Hero* hero);
//void save_game();
//void read_hero(string* prevGameData, int i);
//void read_game_status();
//void new_game(int numOfWarriors,int numOfThieves,int numOfNecromancer,Hero** Heroes);
//void remove();
void print_game();




int main(int argc,char* argv[]) {
	Hero **Heroes;
	Hero* player;
	int counterHeroes;
	bool flag=false;
	int losers=0;


	int round=1;
	int currentPlayer=0;
	int numOfHeroes=0;
	int numOfWarrior=0;
	int numOfThief=0;
	int numOfNecromancer=0;



	if(argc!=5 && argc!=2)
	{
		throw invalidArgs();
	}

	//NEW GAME////
	else if(argc==5)
	{
		//ifExist old game


		DIR* dir = opendir("Players");
		if (dir)
		{
		    /* Directory exists. */
		    closedir(dir);
			string line1;

			ifstream gameData;
			gameData.open("Game/Game.txt");
			if (gameData.fail())
			{
				cout << "File opening error. " << endl;
			}

			string* gameDataDetails = new string[15];
			int counter1 = 0;

			while (getline(gameData, line1))
			{
				gameDataDetails[counter1] = line1;
				counter1++;
			}


			int i=0;
			int counter2=6;//name of players

			int num=atoi(gameDataDetails[2].c_str());

			while (i < num)
			{

				ifstream HeroData;
				string temp=gameDataDetails[counter2];
				string removeFile = "Players/" + temp + "/Details.txt";
				string removeDir = "Players/" + temp;
				remove(removeFile.c_str());
				remove(removeDir.c_str());

				counter2++;
				i++;
			}
			remove("Game/Game.txt");
			remove("Game");

			remove("Players");

			gameData.close();
			delete[] gameDataDetails;
		}





		flag=true;

		int numOfWarriors= atoi(argv[2]);
		int numOfThieves=atoi(argv[3]);
		int numOfNecromancer= atoi(argv[4]);

		if(numOfWarriors> 3 || numOfThieves > 3 || numOfNecromancer > 3){
			cout << "Invalid arguments, num of each hero can't be bigger then 3  "<<endl;
			return 0;
		}


		numOfHeroes=numOfWarriors+numOfThieves+numOfNecromancer;
		Heroes= new Hero*[numOfHeroes];







		//INSERT ALL HEROES FROM THE PLAYERS
		counterHeroes=0;
		string name;

				int j;
				for ( j= 0; j < numOfWarriors; j++)
				{
					cout << "Please insert warrior number " << j + 1 << " name:";
					cin >> name;
					try{
						if((Heroes[counterHeroes])->checkName(name)==true)
						{
							Heroes[counterHeroes] = new Warrior(name);
							counterHeroes++;

						}
						else
						{
							throw chekName();
						}
					} catch (Exception & e) {
						e.Handle();
						j--;
					}

				}
				for ( j= 0; j < numOfThieves; j++)
				{
					cout << "Please insert thief number " << j + 1 << " name:";
					cin >> name;
					try{
						if((Heroes[counterHeroes])->checkName(name)==true)
						{
							Heroes[counterHeroes] = new Thief(name);
							counterHeroes++;
						}
						else
						{
							throw chekName();

						}
					} catch (Exception & e) {
						e.Handle();
						j--;
					}

				}
				for ( j= 0; j < numOfNecromancer; j++)
				{
					cout << "Please insert necromancer number " << j + 1 << " name:";
					cin >> name;
					try{
						if((Heroes[counterHeroes])->checkName(name)==true)
						{
							Heroes[counterHeroes] = new Necromancer(name);
							counterHeroes++;
						}
						else
						{
							throw chekName();

						}
					} catch (Exception & e) {
						e.Handle();
						j--;
					}

				}

			srand(time(NULL));
			currentPlayer=rand()%(numOfHeroes);
			player = Heroes[currentPlayer];//this is the player now.

	}

	//CONTUNE THE LAST GAME
	else if(argc==2)
	{


		//read_game_status();
		string currentLine;
		round=1;
		currentPlayer=0;
		numOfHeroes=0;
		numOfWarrior=0;
		numOfThief=0;
		numOfNecromancer=0;



		//read from game file.
		ifstream Data;
		Data.open("Game/Game.txt");
		if (Data.fail())
		{
			cout << "File opening error. " << endl;
		}

		string* gameDataDetails2 = new string[15];
		int counter5 = 0;

		while (getline(Data, currentLine))
		{
			gameDataDetails2[counter5] = currentLine;
			counter5++;
		}

		round=atoi(gameDataDetails2[0].c_str());
		currentPlayer=atoi(gameDataDetails2[1].c_str());
		numOfHeroes=atoi(gameDataDetails2[2].c_str());
		numOfWarrior=atoi(gameDataDetails2[3].c_str());
		numOfThief=atoi(gameDataDetails2[4].c_str());
		numOfNecromancer=atoi(gameDataDetails2[5].c_str());

		Heroes= new Hero*[numOfHeroes];



		string* readFile = new string[15];
		int i1=0;
		int counter6=6;
		int counter3;
		while (i1 < numOfHeroes)
		{
			counter3=0;
			ifstream HeroData;
			string temp=gameDataDetails2[counter6];
			string Path = "Players/" + temp + "/Details.txt";
			HeroData.open(Path.c_str());
			string HeroLine;
			while (getline(HeroData, HeroLine)) {
				readFile[counter3] = HeroLine;
				counter3++;
			}
			//read_hero(prevGameData, i);//read one hero
			string name= readFile[0];

			string type=readFile[1];

			int gold=atoi(readFile[2].c_str());
			int dailyGold=atoi(readFile[3].c_str());
			int SPAbility=atoi(readFile[4].c_str());
			int isHeroAlive=atoi(readFile[5].c_str());
			int numOfZombie=atoi(readFile[6].c_str());
			int numOfArcher=atoi(readFile[7].c_str());
			int numOfVampire=atoi(readFile[8].c_str());
			int numOfWizard=atoi(readFile[9].c_str());
			int numOfBlackDragon=atoi(readFile[10].c_str());
			if (type == "Warrior")
			{

				Heroes[i1] = new Warrior(name);
				Heroes[i1]->setName(name);
				Heroes[i1]->setGold(gold);
				Heroes[i1]->setdailyGold(dailyGold);
				Heroes[i1]->setSPAbility(SPAbility);
				Heroes[i1]->setisHeroAlive(isHeroAlive);
				Heroes[i1]->setnumOfZombie(numOfZombie);
				Heroes[i1]->setnumOfArcher(numOfArcher);
				Heroes[i1]->setnumOfVampire(numOfVampire);
				Heroes[i1]->setnumOfWizard(numOfWizard);
				Heroes[i1]->setnumOfBlackDragon(numOfBlackDragon);



			}
			else if (type == "Thief")
			{

				Heroes[i1] = new Thief(name);
				Heroes[i1]->setName(name);
				Heroes[i1]->setGold(gold);
				Heroes[i1]->setdailyGold(dailyGold);
				Heroes[i1]->setSPAbility(SPAbility);
				Heroes[i1]->setisHeroAlive(isHeroAlive);
				Heroes[i1]->setnumOfZombie(numOfZombie);
				Heroes[i1]->setnumOfArcher(numOfArcher);
				Heroes[i1]->setnumOfVampire(numOfVampire);
				Heroes[i1]->setnumOfWizard(numOfWizard);
				Heroes[i1]->setnumOfBlackDragon(numOfBlackDragon);
			}
			else if (type == "Necromancer")
			{


				Heroes[i1] = new Necromancer(name);
				Heroes[i1]->setName(name);
				Heroes[i1]->setGold(gold);
				Heroes[i1]->setdailyGold(dailyGold);
				Heroes[i1]->setSPAbility(SPAbility);
				Heroes[i1]->setisHeroAlive(isHeroAlive);
				Heroes[i1]->setnumOfZombie(numOfZombie);
				Heroes[i1]->setnumOfArcher(numOfArcher);
				Heroes[i1]->setnumOfVampire(numOfVampire);
				Heroes[i1]->setnumOfWizard(numOfWizard);
				Heroes[i1]->setnumOfBlackDragon(numOfBlackDragon);
			}
			//////////////////////////////////////////
			HeroData.close();
			counter6++;
			i1++;
		}
		Data.close();
		delete[] gameDataDetails2;
		delete[] readFile;
		//////////removeALL
		//remove();
		string line1;

		ifstream gameData;
		gameData.open("Game/Game.txt");
		if (gameData.fail())
		{
			cout << "File opening error. " << endl;
		}

		string* gameDataDetails = new string[15];
		int counter1 = 0;

		while (getline(gameData, line1))
		{
			gameDataDetails[counter1] = line1;
			counter1++;
		}


		int i=0;
		int counter2=6;//name of players

		while (i < numOfHeroes)
		{
			//counter3=0;
			ifstream HeroData;
			string temp=gameDataDetails[counter2];
			string removeFile = "Players/" + temp + "/Details.txt";
			string removeDir = "Players/" + temp;
			remove(removeFile.c_str());
			remove(removeDir.c_str());

			counter2++;
			i++;
		}
		remove("Game/Game.txt");
		remove("Game");

		remove("Players");

		gameData.close();
		delete[] gameDataDetails;
		flag=true;
		player = Heroes[currentPlayer];//this is the player now.

	}



	int choise =-1;
	if(flag==false)
	{
		choise=7;
	}

	while (choise!=7)
	{
		cout << "Welcome " << player->getName() << "\n";
		print_game();
		/*
		cout << "What is your next step in the path to victory?\n";
		cout << "1.Attack\n";
		cout << "2.Get daily gold\n";
		cout << "3.Buy creatures\n";
		cout << "4.Show details\n";
		cout << "5.Special skill\n";
		cout << "6.End of my turn\n";
		cout << "7.Exit\n";
		*/

cin >> choise;
		switch (choise)
		{
		//Attack
		case 1: {
			int choice2;
			cout<<"1. Show me my opponents"<<endl;
			cout<<"2. Attack hero"<<endl;
			cin>>choice2;
			switch(choice2){
				// Show me my opponents
				case 1:	{
					int k;
					for(k=0;k<numOfHeroes-1;k++)
					{
						if(Heroes[k]->getName().compare(player->getName())!=0 &&Heroes[k]->getisHeroAlive()==true)
						{
							cout<<Heroes[k]->getName()<<" "<<Heroes[k]->getType()<<endl;
						}
					}
					if(Heroes[numOfHeroes-1]->getName().compare(player->getName())!=0 &&Heroes[numOfHeroes-1]->getisHeroAlive()==true)
					{
						cout<<Heroes[k]->getName()<<" "<<Heroes[k]->getType();
					}
					fgetc(stdin);
					cin.ignore();
					break;
				}
				//Attack hero
				case 2:	{
					//try{
				if(round>=3){
					bool flag;
					flag=false;
					int heroesToAttack;
					heroesToAttack=-1;
					while(flag==false){
						string opponent;
						cout<<"Please insert your opponent name:"<<endl;
						cin >> opponent;
						int k;
						bool flag2=false;
						try{
							for (k=0;k<numOfHeroes;k++)
							{

								if (Heroes[k]->getName() == opponent && Heroes[k]->getName()!= player->getName()&& Heroes[k]->getisHeroAlive()==true)
								{
									flag2=true;
									heroesToAttack=k;

								}
							}
							if(flag2==false)
							{
								throw heroNameNotExists();
							}
						}
						catch(Exception &e)
						{
							e.Handle();
							continue;
						}
						flag=true;
				}
				Hero* theAttacker;
				theAttacker = player;
				Hero* theDefender;
				theDefender=Heroes[heroesToAttack];

				while (theAttacker->getisHeroAlive()==true && theDefender->getisHeroAlive()==true)
				{
					theAttacker->Display();
					//cout<<""<<endl;
					theDefender->Display();
					cout<<theAttacker->getName()<<"'s turn:"<<endl;
					try
					{
						string cretureAttacker;
						string cretureDefenser;
						cin>>cretureAttacker;
						cin>>cretureDefenser;


						int indexOfCretureAttack=theAttacker->checkCretureName(cretureAttacker);
						int indexOfCretureDefence=theDefender->checkCretureName(cretureDefenser);
						int tempIndex=-1;

						if(indexOfCretureAttack==-1 ||indexOfCretureDefence==-1)
						{
							throw invalidNameCreture();
						}
						theAttacker->attack(*theDefender,indexOfCretureAttack,indexOfCretureDefence);

						//swap between the players.
						Hero* tempHero;
						tempHero=theAttacker;
						theAttacker=theDefender;
						theDefender=tempHero;


					}
					catch (Exception & e)
					{
						e.Handle();
						//continue;
					}



				}
					if(player->getisHeroAlive()==false)
					{
						cout<<"you have been perished"<<endl;
						player=Heroes[heroesToAttack];

					}
					else
					{
						cout<<"you have been victorious"<<endl;


					}

					losers=losers+1;
					if(losers==numOfHeroes-1)
					{
						cout<<player->getName()<<" is the winner!"<<endl;

						for(int i=0;i<numOfHeroes;i++)
						{
							delete Heroes[i];
						}
						delete[] Heroes;
						choise=7;
					}

				}
				else
				{
					cout<<"you can't attack before third round."<<endl;
				}
				break;
			}
			}
			break;
		}







		//Get daily gold
		case 2:
			if(player->getDailyGold()==false)
			{
				player->addGold(100);
				player->changeDailyGold();
			}
		break;

		//Buy creatures\n
		case 3:
			bool flag3;
			flag3=true;
			try
			{
				flag3=player->buyCreatures();
				if(flag3==false)
				{
					throw HeroNoGold();
				}

			} catch (Exception & e) {
				e.Handle();
			}
		break;
		//Show details
		case 4:
			player->printHero();
		break;



		//Special skill
		case 5:


			if(player->getSAbility()==true)
			{
				break;
			}

			if(player->getType().compare("Warrior")==0)
			{

				player->addGold(50);
				player->changeSAbility();
				cout<<"‫‪Gold‬‬ ‫‪added‬‬ successfully‬‬"<<endl;
			}

			else if(player->getType().compare("Necromancer")==0)
			{

				player->SpecialAbility(*player);
				player->changeSAbility();
				cout<<"‫‪Zombie ‫‪added‬‬ successfully‬‬"<<endl;
			}


			else if(player->getType().compare("Thief")==0)
			{
				bool flag4=false;
				while(flag4==false)
				{
					cout<<"Please insert hero name:"<<endl;
					string tempName;
					cin>>tempName;
					try
					{
						int w=0;
						int save=0;
						for(w=0;w<numOfHeroes;w++)
						{
							if(Heroes[w]->getName().compare(tempName)==0 && player->getName().compare(tempName)!=0)
							{
								flag4=true;
								save=w;
							}
						}

						if(flag4==false)
						{
							throw heroNameNotExists();
						}
						else
						{
							Hero* tempHero;
							tempHero = Heroes[save];
							player->SpecialAbility(*tempHero);
							player->changeSAbility();
						}


						} catch (Exception & e) {
							e.Handle();
						}
				}



			}

			break;


			//End of my turn
			case 6:
				//this player end the game
				if(player->getDailyGold()==true)
				{
					player->changeDailyGold();
				}
				if(player->getSAbility()==true)
				{
					player->changeSAbility();
				}
				//move to the next player
				bool flag5;
				flag5=false;
				int counter;
				counter=0;
				while(flag5==false)
				{
					counter=currentPlayer+1;
					if(counter==numOfHeroes)
					{
						currentPlayer=0;
					}
					else
					{
						currentPlayer=counter;
					}

					player = Heroes[currentPlayer];//this is the player now.
					if(player->getisHeroAlive()==true)
					{
						flag5=true;
					}

				}

				round++;

				break;


				//Exit
				case 7:

					//save_game();
					mkdir("Game",0777);
					ofstream gameFile("Game/Game.txt");
					gameFile<<round<<endl;
					gameFile<<currentPlayer<<endl;
					gameFile<<numOfHeroes<<endl;
					gameFile<<numOfWarrior<<endl;
					gameFile<<numOfThief<<endl;
					gameFile<<numOfNecromancer<<endl;

					for(int i=0;i<numOfHeroes;i++)
					{
						gameFile<<Heroes[i]->getName()<<endl;
					}


					gameFile.close();
					mkdir("Players",0777);
					for(int i=0; i<numOfHeroes; i++)
					{
						if(Heroes[i]->getisHeroAlive()==true)
						{
							//save_hero(Heroes[i]);
							string heroPath = "Players/" + Heroes[i]->getName();
							mkdir(heroPath.c_str(), 0777);

							//string filePath = heroPath+"/"+hero->getName()+".txt";
							string filePath = heroPath+"/Details.txt";
							ofstream heroFile(filePath.c_str());
							heroFile<<Heroes[i]->getName()<<endl;
							heroFile<<Heroes[i]->getType()<<endl;
							heroFile<<Heroes[i]->getGold()<<endl;
							heroFile<<Heroes[i]->getDailyGold()<<endl;
							heroFile<<Heroes[i]->getSAbility()<<endl;
							heroFile<<Heroes[i]->getisHeroAlive()<<endl;
							heroFile<<Heroes[i]->getNumOfCreatures(0)<<endl;
							heroFile<<Heroes[i]->getNumOfCreatures(1)<<endl;
							heroFile<<Heroes[i]->getNumOfCreatures(2)<<endl;
							heroFile<<Heroes[i]->getNumOfCreatures(3)<<endl;
							heroFile<<Heroes[i]->getNumOfCreatures(4)<<endl;

							heroFile.close();


						}

					}


					for(int i=0;i<numOfHeroes;i++)
					{
						delete Heroes[i];
					}
					delete[] Heroes;

				break;



				}//switch
			//}//switch
			}//while
			return 0;
		}//main






				void print_game()
				{
					cout << "What is your next step in the path to victory?\n";
					cout << "1. Attack\n";
					cout << "2. Get daily gold\n";
					cout << "3. Buy creatures\n";
					cout << "4. Show details\n";
					cout << "5. Special skill\n";
					cout << "6. End of my turn\n";
					cout << "7. Exit\n";
				}




