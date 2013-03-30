#ifndef MONSTER_H
#define MONSTER_H
// This is the Monster class. The monster class
// provides a placeholder for special monster descriptions
// and allows for monsters of a certain level to be initialized

#include "Character.h"
#include <string>

using std::string;

class Monster : public Character
{
private:
	string _name;
	string _attackMethod;
	string _description;
	void type();
public:
	Monster();
	Monster(int);
	string getName();
	string getAttackMethod();
	string getDesc();
};

#endif