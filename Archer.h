

#ifndef ARCHER_H_
#define ARCHER_H_
#include "Creature.h"

class Archer:public Creature{
public:
	Archer();
	virtual void specialAbility(Creature &other);
	virtual void Fight(Creature &other);
	virtual ~Archer(){};
};




#endif /* ARCHER_H_ */
