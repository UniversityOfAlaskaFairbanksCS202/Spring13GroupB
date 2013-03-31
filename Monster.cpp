// John Cheshire / Group B
// 03/31/2013
//
// This file implements the Monster class

#include "Monster.h"
#include <cstdlib>

using std::rand;

// The constructor sets up the various attributes of the
// monster with some randomization.
Monster::Monster(int level)
{
	_attack = level*10 + (1 + rand() % 10);
    _hitPoints = level*10 + (1 + rand() % 10);
    _maxHitPoints = _hitPoints;
    _defense = level*10 + (1 + rand() % 10);
    _dodge = level*10 + (1 + rand() % 10);
    _mana = 0;
    _maxMana = _mana;
    _weaponDamage = level*10 + (1 + rand() % 10);
    _level = level;
	type();
}

// This private member function randomly determines
// the type of monster the player encounters.
void Monster::type()
{
	switch(1 + rand() % 4)
	{
		case 1:
			_name = "West End Ogre";
			_attackMethod = "The West End Ogre swings his club.";
			_description = "A West End Ogre, stinking of rotting flesh, stands before you.";
			break;
		case 2:
			_name = "Dungeon Rat";
			_attackMethod = "The dungeon rat bites at your legs.";
			_description = "You hear a scurry and look down to see a large rat.";
			break;
		case 3:
			_name = "Man-eating Spider";
			_attackMethod = "The man-eating spider jumps toward you ready to bite.";
			_description = "A spider as big as a dog slides down from the ceiling.";
			break;
		case 4:
			_name = "Devil Cat";
			_attackMethod = "The devil cat hisses and swipes at you.";
			_description = "A devil cat jumps down from a ledge and postures before you.";
			break;
	}
}

string Monster::getName()
{
	return _name;
}

string Monster::getAttackMethod()
{
	return _attackMethod;
}

string Monster::getDesc()
{
	return _description;
}