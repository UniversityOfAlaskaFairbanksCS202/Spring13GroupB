#include "ui.h"


void  UI::keyDown( char key, Dungeon & myDungeon )
{
	myDungeon.ChangeRoom(key);
	
	
}
