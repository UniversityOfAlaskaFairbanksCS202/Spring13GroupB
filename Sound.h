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
	Sound();
	void setup();
	void launch();



private:
	audio::SourceRef currentSound_;

};



#endif