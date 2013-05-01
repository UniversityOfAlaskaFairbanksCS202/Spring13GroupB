// John Cheshire / Group B
// 03/31/2013
//
// This file implements the Monster class

#include "Monster.h"

// The constructor sets up the various attributes of the
// monster with some randomization.
Monster::Monster(int level)
{
	// These constants specify how many random points can be added to
	// attributes when initializing a character
	const int MIN_VARIATION = 0;
	const int MAX_VARIATION = 6; // One above max

	_attack = level*10 + Rand::randInt(MIN_VARIATION, MAX_VARIATION);
    _hitPoints = level*10 + Rand::randInt(MIN_VARIATION, MAX_VARIATION);
    _maxHitPoints = _hitPoints;
    _defense = level*10 + Rand::randInt(MIN_VARIATION, MAX_VARIATION);
    _weaponDamage = 3 + Rand::randInt(MIN_VARIATION, MAX_VARIATION);
    _level = level;
	type();
}

// This private member function randomly determines
// the type of monster the player encounters.
void Monster::type()
{
	int randType = Rand::randInt(1,5);
	switch(randType)
	{
		case 1:
			_name = "West End Ogre";
			_attackMethod = "The West End Ogre swings his club.";
			_description = "A West End Ogre, stinking of rotting flesh, stands before you.";
			_monsterImg = gl::Texture(loadImage(loadResource(MONS___1)));
			break;
		case 2:
			_name = "Dungeon Rat";
			_attackMethod = "The dungeon rat bites at your legs.";
			_description = "You hear a scurry and look down to see a large rat.";
			_monsterImg = gl::Texture(loadImage(loadResource(MONS___2)));
			break;
		case 3:
			_name = "Man-eating Spider";
			_attackMethod = "The man-eating spider jumps toward you ready to bite.";
			_description = "A spider as big as a dog slides down from the ceiling.";
			_monsterImg = gl::Texture(loadImage(loadResource(MONS___3)));
			break;
		case 4:
			_name = "Devil Cat";
			_attackMethod = "The devil cat hisses and swipes at you.";
			_description = "A devil cat jumps down from a ledge and postures before you.";
			_monsterImg = gl::Texture(loadImage(loadResource(MONS___4)));
			break;
	}
}
// Basic get functions
string Monster::getName() const
{
	return _name;
}

string Monster::getAttackMethod() const
{
	return _attackMethod;
}

string Monster::getDesc() const
{
	return _description;
}

gl::Texture Monster::getImage() const
{
	return _monsterImg;
}