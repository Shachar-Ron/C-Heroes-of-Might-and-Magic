/*
 * Exception.h
 *
 *  Created on: Jan 3, 2019
 *      Author: ise
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
using namespace std;

class Exception {

public:
	Exception(){};
	virtual void Handle()const = 0 ;
	virtual ~Exception(){};
};

class invalidArgs:public Exception {
public:
	invalidArgs(): Exception() {};
	virtual void Handle()const { cout << "Invalid arguments, please try again."<< endl ;};
};

class chekName:public Exception {
public:
	chekName(): Exception() {};
	virtual void Handle()const { cout << "Invalid name, please try again."<< endl ;};
};

class invalidNameCreture:public Exception {
public:
	invalidNameCreture(): Exception() {};
	virtual void Handle()const  { cout << "Invalid name, please try again." << endl ;};
};

class HeroNoGold:public Exception {
public:
	HeroNoGold() : Exception() {};
	virtual void Handle()const { cout <<"You don't have enough gold" << endl;};

};


class heroNameNotExists:public Exception {
public:
	heroNameNotExists(): Exception() {};
	virtual void Handle()const  { cout << "Hero name does not exist" << endl ;};
};
class creatureNotExists:public Exception {
public:
	creatureNotExists(): Exception() {};
	virtual void Handle()const  { cout << "Creature name does not exist, please try again" << endl ;};
};



#endif /* EXCEPTION_H_ */
