//ui.h
// ross spicer
//
//	this class is for user inteaction
//
#ifndef UI_HEADER_FILE
#define UI_HEADER_FILE
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "dungeon.h"
#include "Player.h"
#include "ImportantMessage.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// class for the user interface
class UI
{
public:
	//void  UI::keyDown(char key, Dungeon & myDungeon , Player & myPlayer, ImportantMessage & splash)
	//		this is the ui function for key presses
	//	pramaters
	//		key -- the key presed
	//      myDungeon -- the games dungeon
	//		myPlayey --  the games player
	//		splash -- for iportant messeges 
	//
	void keyDown( char key, Dungeon & myDungeon , Player & myPlayer, ImportantMessage & splash );
};





#endif