/*
Chay Davis
CS 202
Group B

May 3, 2013

*/

#ifndef SOUND_H
#define SOUND_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/audio/Output.h"
#include "cinder/audio/Io.h"
#include <iostream>

using namespace ci;
using namespace ci::app;
using namespace std;

class Sound
{
public:

	//enum attacking {,,,}
	//enum monster{,,,,,,}

	void attackSetup1();//initializes all the sound setups
	void attackSetup2();
	void attackSetup3();
	void attackSetup4();
	void magicAttackSetup();
	void screechSetup();
	void monsterScreechSetup();
	void swallowSetup();
	void snarlSetup();
	void superSnarlSetup();
	void doorNoiseSetup();
	void dragonHissSetup();
	void hissSetup();
	void hybridGrowlSetup1();
	void hybridGrowlSetup2();

	void launch();

private:
	audio::SourceRef currentSound_;

};

#endif