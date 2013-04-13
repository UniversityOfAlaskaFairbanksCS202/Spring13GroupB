#include "ui.h"

//void  UI::keyDown( char key, Dungeon & myDungeon )
//		this is the ui function for key presses
//
void  UI::keyDown( char key, Dungeon & myDungeon )
{
	// ui for movement
	if ((key == 'w')||(key == 'a')||(key == 'd'))
	{
		myDungeon.ChangeRoom(key);
	}
	
}
