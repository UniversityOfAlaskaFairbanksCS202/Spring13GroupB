//
//  Player.cpp
//  Character
//
//  Created by RX-78 01 on 3/26/13.
//  Copyright (c) 2013 lilongyue. All rights reserved.
//

#include "Player.h"


Player::Player(Messenger &msg)
{
	_msg = &msg;
    _attack = 10 + Rand::randInt (1, 11);
    _hitPoints = 10 + Rand::randInt (1, 11);
    _maxHitPoints = _hitPoints;
    _defense = 10 + Rand::randInt (1, 11);
    _mana = 10 + Rand::randInt (1, 11);
    _maxMana = _mana;
    _weaponDamage = 8;
    _magicDamage = 5 ;
    _hpPotion = 10;
    _manaPotion = 10;
    _experience = 0;
    _level = 1;
    _numHPPotions = 1;
    _numManaPotions = 1;
}

Player::fightVictor Player::turn(Monster &monster, attackOption choice)
{
	ostringstream oss;

    bool isDead = false;
	int damage = 0;
    
    switch(choice)
    {
        //normal attack
        case 0:
			damage = attack(monster.getDefense() - Rand::randInt (1, 6));
            isDead = monster.hit(damage);
			if (damage > 0)
				oss << "You attack the monster, doing " << damage << " points of damage.";
			else
				oss << "Your attack missed.";
			_msg->newMessage(oss.str());
			oss.str("");
            break;
        //magic attack
        case 1:
			if(_mana > 0)
			{
				isDead = monster.hit(_magicDamage);
				oss << "You attack with magic, doing " << _magicDamage << " points of damage.";
				_msg->newMessage(oss.str());
				decrementMana();
				oss.str("");
			}
			else
				_msg->newMessage("You have no manna left!");
			break;
        //drink HP potion
        case 2:
			drinkHPPotion();
			break;
        //drink mana potion
        case 3:
				drinkManaPotion();
			break;
    }

	if(isDead)
    {
		_msg->newMessage("You have killed the monster.");
		return PLAYER;
    }

	damage = monster.attack(_defense - Rand::randInt (1, 3));

    isDead = hit(damage);

	if (damage > 0)
		oss << "The monster hits you, doing " << damage << " points of damage.";
	else
		oss << "The monster's attack misses.";
    
	_msg->newMessage(oss.str());

    if(isDead)
    {
        return MONSTER;
    }
    else
    {
        return NEITHER;
    }

}

bool Player::randomEncounter()//function for randomly generating an enemy encounter
{
    int chanceOfEncouter = 65;
    
    bool enemyEncountered = false;
    int randomChanceOfEncounter = 0;
    randomChanceOfEncounter = (Rand::randInt (1, 101));
    //cout << randomChanceOfEncounter << endl;
    if(randomChanceOfEncounter > chanceOfEncouter)
        enemyEncountered = true;
    return enemyEncountered;
}

//void Player::levelingSystem()
//	the leveling system for the character
//  update 1 -- updated the the attack, defense , 
//		and hitpoits to grow each level -- ross
//	update 2 -- added final level -- ross
//	update 3 -- max HP now chahes to -- ross
//	update 4 -- mana levels now
void Player::levelingSystem()
{
    ostringstream oss;
    
    if(_experience >= 100 && _level == 1)
    {
        _level ++;
        _maxHitPoints += 10 +Rand::randInt (1, 11);
		_hitPoints = _maxHitPoints;
        _attack += 3 + Rand::randInt (1, 11);
        _defense += 3 + Rand::randInt (1, 11);
		_maxMana += 5 + Rand::randInt (1, 11);
		_mana = _maxMana;
        oss << "You are now level " << _level << ".";
        _msg->newMessage(oss.str());
        oss.str("");//add after each
        oss << "Your hit points are now " << _hitPoints << ", your attack is now " << _attack << ", your dodge is now " << _defense << ".";
        _msg->newMessage(oss.str());
        oss.str("");
        
    }
    
    if(_experience >= 275 && _level == 2)
    {
        _level ++;
        _maxHitPoints += 10 +Rand::randInt (1, 11);
		_hitPoints = _maxHitPoints;
        _attack += 5 + Rand::randInt (1, 11);
        _defense += 5 + Rand::randInt (1, 11);
		_maxMana += 5 + Rand::randInt (1, 11);
		_mana = _maxMana;
        oss << "You are now level " << _level << ".";
        _msg->newMessage(oss.str());
        oss.str("");
        oss << "Your hit points are now " << _hitPoints << ", your attack is now " << _attack << ", your dodge is now " << _defense << ".";
        _msg->newMessage(oss.str());
        oss.str("");
        
    }
    if(_experience >= 470 && _level == 3)
    {
        _level ++;
        _maxHitPoints += 10 +Rand::randInt (1, 11);
		_hitPoints = _maxHitPoints;
        _attack +=  8 + Rand::randInt (1, 11);
        _defense += 8 + Rand::randInt (1, 11);
		_maxMana += 5 + Rand::randInt (1, 11);
		_mana = _maxMana;
        oss << "You are now level " << _level << ".";
        _msg->newMessage(oss.str());
        oss.str("");
        oss << "Your hit points are now " << _hitPoints << ", your attack is now " << _attack << ", your dodge is now " << _defense << ".";
        _msg->newMessage(oss.str());
        oss.str("");
    }
    if(_experience >= 680 && _level == 4)
    {
        _level ++;
        _maxHitPoints += 10 +Rand::randInt (1, 11);
		_hitPoints = _maxHitPoints;
        _attack += 13 + Rand::randInt (1, 11);
        _defense += 13 + Rand::randInt (1, 11);
		_maxMana += 5 + Rand::randInt (1, 11);
		_mana = _maxMana;
        oss << "You are now level " << _level << ".";
        _msg->newMessage(oss.str());
        oss.str("");
        oss << "Your hit points are now " << _hitPoints << ", your attack is now " << _attack << ", your dodge is now " << _defense << ".";
        _msg->newMessage(oss.str());
        oss.str("");
        
    }
	// this level means you won
	if (_experience >= 1000 && _level == 5)
	{
		_level ++;
		oss << "You are now level " << _level << "You Win.";
		_msg->newMessage(oss.str());
        oss.str("");
	}
}

// void Player::enemyDrop (Monster & monster)
// function for generating what items an enemy drops when killed
//     update 1 -- change param from monster to monster reference - ross
//	   update 2 -- based exp gaind on monster lvl -ross
void Player::enemyDrop (Monster & monster)
{
    ostringstream oss;
	int tempExp = 10 + Rand::randInt (1, monster.getLevel()*10+1);
	_experience += tempExp;
    oss << "You got " << tempExp << " experience points.";
    _msg->newMessage(oss.str());
    oss.str("");
	oss << "You have " << _experience << " experience points.";
    _msg->newMessage(oss.str());
    oss.str("");
    levelingSystem();
    
    int baseEnemyDropPercentage = 35;
    int randomEnemyDropPercentage = 0;
    
    int numPotions = 0;
    int potionDropPercentage = 70;
    int randomPotionDropPercentage = 0;
    
    int numCoins = 0;
    int coinDropPercentage = 30;
    int randomCoinDropPercentage = 0;
    
    randomEnemyDropPercentage = Rand::randInt (1, 101);
    //cout << "Random enemy drop percentage is " << randomEnemyDropPercentage << endl;
    if(randomEnemyDropPercentage > baseEnemyDropPercentage)
    {
        randomPotionDropPercentage = Rand::randInt (1, 101);
        if(randomPotionDropPercentage > potionDropPercentage)
        {
            int kindOfPotion;
            kindOfPotion = Rand::randInt(1,3);
            if(kindOfPotion == 1)
            {
                oss << "You got an HP potion!";
                _msg->newMessage(oss.str());
                oss.str("");
                addHPPotion(numPotions);
            }
            else
            {
                oss << "You got a mana potion!";
                _msg->newMessage(oss.str());
                oss.str("");
                addManaPotion(numPotions);
            }
 
        }
        randomCoinDropPercentage = Rand::randInt (1, 11);
        if(randomCoinDropPercentage > coinDropPercentage)
        {
            numCoins = Rand::randInt (1, 11);
            oss << "You got " << numCoins << " coins.";
            _msg->newMessage(oss.str());
            oss.str("");
            addCoins(numCoins);
        }
    }
    
}


// canidate for deletion i don't think we use this 
// and it isn't even set up to work with messenger -- ross
void Player::treasureChest()//randomly generates chests for the player to find
{
    //cout << "Called the treasure chest function" << endl;
    int baseChanceOfChest = 50;
    int randomChanceOfChest = Rand::randInt (1, 101);
    
    int numPotions = 0;
    int potionDropPercentage = 70;
    int randomPotionDropPercentage = 0;
    
    int numCoins = 0;
    int coinDropPercentage = 30;
    int randomCoinDropPercentage = 0;
    
    if(randomChanceOfChest > baseChanceOfChest)
    {
        char chestInput;
        cout << "You see a chest.  Open it?  Type 'Y' for yes, or 'N' for no." << endl;
        cin >> chestInput;
        if(toupper(chestInput) == 'Y')
        {
            randomPotionDropPercentage = Rand::randInt (1, 101);
            if(randomPotionDropPercentage > potionDropPercentage)
            {
                cout << "You got a potion!" << endl;
                numPotions ++;
                addHPPotion(numPotions);
                
            }
            randomCoinDropPercentage = Rand::randInt (1, 101);
            if(randomCoinDropPercentage > coinDropPercentage)
            {
                numCoins = Rand::randInt (1, 11);
                cout << "You got " << numCoins << " coins." << endl;
                addCoins(numCoins);
            }
            else
            {
                cout << "The chest is empty." << endl;
            }
            
        }
        if(toupper(chestInput) == 'N')
        {
            cout << "You decide not to open the chest and move on." << endl;
        }
    }
}

void Player::movementDescription()//called when the player moves, gives some description of the surroundings to spice things up
{
    ostringstream oss;
    int randomDescription;
    randomDescription = Rand::randInt (1, 11);
    switch(randomDescription)
    {
        case 1:
            oss << "Your unease grows with each room.";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 2:
            oss << "How many rooms could there be?";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 3:
            oss << "The air is cold and damp, and the floor slick.";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 4:
            oss << "You smell death.";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 5:
            oss << "Something crunches under your foot.";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 6:
            oss << "A scream pierces the dead silence.";;
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 7:
            oss << "Your heart beats furiously in fear.";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 8:
            oss << "Despite the cold, you're sweating.";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 9:
            oss << "You wonder if you'll ever get out of here.";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
        case 10:
            oss << "You hear a faint dripping sound.";
            _msg->newMessage(oss.str());
            oss.str("");
            break;
    }
    
}
void Player::addHPPotion(int numHPPotions)
{
    _numHPPotions += 1;
}

void Player::addManaPotion(int numManaPotions)
{
    _numManaPotions += 1;
}

void Player::subtractHPPotion()
{
    _numHPPotions -= 1;
}

void Player::subtractManaPotions()
{
    _numManaPotions -= 1;
}

void Player::addCoins (int numCoins)//increments number of coins
{
    _coins += numCoins;
}

void Player::magicAttack()
{
    _mana --;
    //function that decrements monster hp
}

int Player::getMana()
{
    return _mana;
}
void Player::setMana(int mana)
{
    _mana = mana;
}
int Player::getMaxMana()
{
    return _maxMana;
}

void Player::setMaxMana(int maxMana)
{
    _maxMana = maxMana;
}

int Player::getExperience()
{
    return _experience;
}

void Player::setExperience(int exp)
{
    _experience = exp;
}

int Player::getHPPotions()
{
    return _numHPPotions;
}

void Player::setHPPotions(int potions)
{
    _numHPPotions = potions;
}

int Player::getManaPotions()
{
    return _numManaPotions;
}

void Player::setManaPotions(int potions)
{
    _numManaPotions = potions;
}

int Player::getCoins()
{
    return _coins;
}

void Player::setCoins(int coins)
{
    _coins = coins;
}

void Player::drinkHPPotion()
{
	if(_numHPPotions > 0)
	{
		 _hitPoints += _hpPotion;
    
		if(_hitPoints > _maxHitPoints)
		{
			_hitPoints = _maxHitPoints;
		}
		subtractHPPotion();
		_msg->newMessage("Drinking a health potion makes you feel stronger.");
	}
	else
		_msg->newMessage("You have no health potions!");
}
void Player::drinkManaPotion()
{
	if(_numManaPotions > 0)
	{
		_mana += _manaPotion;
    
		if(_mana > _maxMana)
		{
			_mana = _maxMana;
		}
		subtractManaPotions();
		_msg->newMessage("Drinking a magic potion revives your energy.");
	}
	else
		_msg->newMessage("You have no magic potion!");
}

void Player::decrementMana()
{
    _mana -= 1;
}

int Player::getLevel()
{
	return _level;
}
