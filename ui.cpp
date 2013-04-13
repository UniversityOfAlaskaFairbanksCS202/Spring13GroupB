#include "ui.h"


void  UI::keyDown( char key, Dungeon & myDungeon )
{
	//if ((key == 'w')||(key == 'a')||(key == 'd'))
	{
		myDungeon.ChangeRoom(key);
	}
	
}
