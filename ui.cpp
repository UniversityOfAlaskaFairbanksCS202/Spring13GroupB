#include "ui.h"
#include <cstdlib>

//void  UI::keyDown( char key, Dungeon & myDungeon )
//		this is the ui function for key presses
//
void  UI::keyDown( char key, Dungeon & myDungeon , Player & myPlayer, ImportantMessage & splash)
{

	const int EXIT_TIME = 3;
	if (key == '`' )
		{
			exit(0);
		}

	if (myPlayer.getHitPoints() > 0)
	{
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
		
			}
			if (key == 'h')
			{
				myPlayer.drinkHPPotion();
			}
			if (key == 'g')
			{
				myPlayer.drinkManaPotion();
			}

		}
		else
		{
			Player::fightVictor victor;
			if (key == ' ')
			{
			
				victor = myPlayer.turn(myDungeon.getMonster(),Player::ATTACK);
					if (victor == Player::PLAYER)
						{
						myPlayer.enemyDrop(myDungeon.getMonster());
						myDungeon.killMonster();
						}
					if (victor == Player::MONSTER)
						{
							splash.splashMessage("You've Just Died,\nthe Game will now exit", EXIT_TIME, true);
						}
			}
			if (key == 'm')
			{
				victor = myPlayer.turn(myDungeon.getMonster(),Player::MAGICATTACK);
					if (victor == Player::PLAYER)
						{
						myPlayer.enemyDrop(myDungeon.getMonster());
						myDungeon.killMonster();
						}
					if (victor == Player::MONSTER)
						{
							splash.splashMessage("You've Just Died,\r\nthe Game will now exit", EXIT_TIME, true);
						}
			}
			if (key == 'h')	
			{
				victor = myPlayer.turn(myDungeon.getMonster(),Player::DRINKHP);
					if (victor == Player::MONSTER)
						{
						splash.splashMessage("You've Just Died,\nthe Game will now exit", EXIT_TIME, true);
						}
			}
			if (key == 'g')
			{
				victor = myPlayer.turn(myDungeon.getMonster(),Player::DRINKMANA);
					if (victor == Player::MONSTER)
						{
							splash.splashMessage("You've Just Died,\nthe Game will now exit", EXIT_TIME, true);
						}

			}
			if (key == '0')
				{
					myPlayer.enemyDrop(myDungeon.getMonster());
					myDungeon.killMonster();
				}
		
		}
		}
	
}
