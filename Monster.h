#ifndef MONSTER_H
#define MONSTER_H
// John Cheshire / Group B
// Date: 03/31/2013
//
// This is the Monster class. The monster class
// provides a placeholder for special monster descriptions
// and allows for monsters of a certain level to be initialized

#include "Character.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/app/AppBasic.h"
#include "Resources.h"
#include <string>

using std::string;
using namespace ci;
using namespace ci::app;

class Monster : public Character
{
private:
	string _name;
	string _attackMethod;
	string _description;
	gl::Texture _monsterImg;
	void type();
public:
	Monster();
	Monster(int);
	string getName();
	string getAttackMethod();
	string getDesc();
	gl::Texture getImage();
};

#endif