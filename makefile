
Heroes: BlackDragon.o Creature.o Hero.o main.o Necromancer.o Thief.o Vampire.o Warrior.o Wizard.o Zombie.o Archer.o
	g++ BlackDragon.o Creature.o Hero.o main.o Necromancer.o Thief.o Vampire.o Warrior.o Wizard.o Zombie.o Archer.o -o Heroes

main.o: main.cpp Hero.h Creature.h BlackDragon.h Zombie.h Vampire.h \
Archer.h Wizard.h Exception.h Warrior.h Thief.h Necromancer.h

Warrior.o: Warrior.cpp Warrior.h Hero.h Creature.h BlackDragon.h Zombie.h \
Vampire.h Archer.h Wizard.h Exception.h

Vampire.o: Vampire.cpp Vampire.h Creature.h

Archer.o: Archer.cpp Archer.h Creature.h

Hero.o: Hero.cpp Hero.h Creature.h BlackDragon.h Zombie.h Vampire.h \
Archer.h Wizard.h Exception.h

BlackDragon.o: BlackDragon.cpp BlackDragon.h Creature.h

Exception.o: Exception.cpp Exception.h

Necromancer.o: Necromancer.cpp Necromancer.h Hero.h Creature.h \
BlackDragon.h Zombie.h Vampire.h Archer.h Wizard.h Exception.h

Thief.o: Thief.cpp Thief.h Hero.h Creature.h BlackDragon.h Zombie.h \
Vampire.h Archer.h Wizard.h Exception.h

Wizard.o: Wizard.cpp Wizard.h Creature.h

Wizard.o: Wizard.cpp Wizard.h Creature.h


clean:
	rm -f *.o Hero
