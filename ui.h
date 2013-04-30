//UI.h
// ross spicer
//
// ver 1: contains the declerations of the 
// functions that will likely be used in the UI Class 
#ifndef UI_HEADER_FILE
#define UI_HEADER_FILE
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "dungeon.h"
#include "Player.h"
#include "Messenger.h"
#include "ImportantMessage.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class UI
{
public:
	void draw();
	void update();
	void keyDown( char key, Dungeon & myDungeon , Player & myPlayer, ImportantMessage & splash );
};





#endif