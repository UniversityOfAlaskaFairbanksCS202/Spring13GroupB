#include "ui.h"
#include <cstdlib>

//void  UI::keyDown( char key, Dungeon & myDungeon )
//		this is the ui function for key presses
//
void  UI::keyDown( char key, Dungeon & myDungeon , Player & myPlayer, Messenger & myMsg)
{

	if (key == '`' )
		{
		exit(0);
		}
	// ui for movement
	if (!myDungeon.occupied())
	{
		if ((key == 'w')||(key == 'a')||(key == 'd'))
		{
			myDungeon.ChangeRoom(key, myPlayer.getLevel());
			myPlayer.movementDescription();
			//myMsg.newMessage("moving"); 
		}
	}
	else
	{
		if (key == ' ')
		{
			//myPlayer.turn(myDungeon.getMonster(),Player::ATTACK);
			myDungeon.killMonster();
		}
		
	}
	
}
