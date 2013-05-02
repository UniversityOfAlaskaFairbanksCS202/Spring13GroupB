/*
Chay Davis
CS 202
Group B

May 3, 2013

*/
#include "Sound.h"
#include "Resources.h"

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/audio/Output.h"
#include <iostream>


void Sound::setup()
{
	currentSound_=audio::load( loadResource( RES_BOOYAHWAV ) );
}

void Sound::launch()
{
	audio::Output::play( currentSound_ );
}