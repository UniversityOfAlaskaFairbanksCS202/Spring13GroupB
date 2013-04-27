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
			bool moved;
			moved = myDungeon.ChangeRoom(key, myPlayer.getLevel());
			if (moved)
				{
				myPlayer.movementDescription();
				}
			//myMsg.newMessage("moving"); 
		}
	}
	else
	{
		Player::fightVictor victor;
		if (key == ' ')
		{
			myMsg.newMessage("You Attack"); 
			victor = myPlayer.turn(myDungeon.getMonster(),Player::ATTACK);
				if (victor == Player::PLAYER)
					{
					myDungeon.killMonster();
					}
				if (victor == Player::MONSTER)
					{
					myMsg.newMessage("You've Just Died, the Game will now exit");
					exit(0);
					}
		}
		if (key == 'm')
		{
			myMsg.newMessage("You Magic"); 
			victor = myPlayer.turn(myDungeon.getMonster(),Player::MAGICATTACK);
				if (victor == Player::PLAYER)
					{
					myDungeon.killMonster();
					}
				if (victor == Player::MONSTER)
					{
					myMsg.newMessage("You've Just Died, the Game will now exit");
					exit(0);
					}
		}
		if (key == 'h')
		{
			myMsg.newMessage("You health potion"); 
			victor = myPlayer.turn(myDungeon.getMonster(),Player::DRINKHP);
				if (victor == Player::PLAYER)
					{
					myDungeon.killMonster();
					}
				if (victor == Player::MONSTER)
					{
					myMsg.newMessage("You've Just Died, the Game will now exit");
					exit(0);
					}
		}
		if (key == 'g')
		{
			myMsg.newMessage("You magic potion"); 
			victor = myPlayer.turn(myDungeon.getMonster(),Player::DRINKMANA);
				if (victor == Player::PLAYER)
					{
					myDungeon.killMonster();
					}
				if (victor == Player::MONSTER)
					{
					myMsg.newMessage("You've Just Died, the Game will now exit");
					exit(0);
					}
		}
		
	}
	
}
