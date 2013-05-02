// ui.cpp
// ross spicer
//
//	this class is for user inteaction
//
#include "ui.h"
#include <cstdlib>

//void  UI::keyDown(char key, Dungeon & myDungeon , Player & myPlayer, ImportantMessage & splash)
//		this is the ui function for key presses
//	pramaters
//		key -- the key presed
//      myDungeon -- the games dungeon
//		myPlayey --  the games player
//		splash -- for iportant messeges 
//
void  UI::keyDown(char key, Dungeon & myDungeon , Player & myPlayer, ImportantMessage & splash)
{
	
	const int EXIT_TIME = 3;

	// player can exit whenever
	if (key == '`' )
	{
		exit(0);
	}

	// show victory messege
	if(myPlayer.getLevel() == 6)
	{	
		splash.splashMessage("You've Just Reached level 6,\n You Win!!, \nthe Game will now exit", EXIT_TIME, true);
	}
	
	// allow commands while alive and less than level 4
	if (myPlayer.getHitPoints() > 0 && myPlayer.getLevel() != 6)
	{
		// ui for movement phase
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
			// heal
			if (key == 'h')
			{
				myPlayer.drinkHPPotion();
			}
			// magic potion
			if (key == 'g')
			{
				myPlayer.drinkManaPotion();
			}
			// cheat for potions
			if (key == '9')
			{
				myPlayer.setHPPotions(1);
				myPlayer.setManaPotions(1);
			}

		}
		// battle phase
		else
		{
			Player::fightVictor victor;

			// attack
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

			// magic attack
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

			// dring HP
			if (key == 'h')	
			{
				victor = myPlayer.turn(myDungeon.getMonster(),Player::DRINKHP);
				if (victor == Player::MONSTER)
				{
					splash.splashMessage("You've Just Died,\nthe Game will now exit", EXIT_TIME, true);
				}
			}

			// drink mana
			if (key == 'g')
			{
				victor = myPlayer.turn(myDungeon.getMonster(),Player::DRINKMANA);
				if (victor == Player::MONSTER)
				{
					splash.splashMessage("You've Just Died,\nthe Game will now exit", EXIT_TIME, true);
				}
			}

			// cheat victory
			if (key == '0')
			{
				myPlayer.enemyDrop(myDungeon.getMonster());
				myDungeon.killMonster();
			}

			// cheat for potions
			if (key == '9')
			{
				myPlayer.setHPPotions(1);
				myPlayer.setManaPotions(1);
			}
		
		}
	}
	
}// end UI::keyDown