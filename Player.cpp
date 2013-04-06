//
//  Player.cpp
//  Character
//
//  Created by RX-78 01 on 3/26/13.
//  Copyright (c) 2013 lilongyue. All rights reserved.
//

#include "Player.h"

Player::Player()
{
    _attack = 10 + (1 +rand % 10);
    _hitPoints = 10 + (1 +rand % 10);
    _maxHitPoints = _hitPoints;
    _defense = 10 + (1 +rand % 10);
    _dodge = 10 + (1 +rand % 10);
    _mana = 10 + (1 +rand % 10);
    _maxMana = _mana;
    _weaponDamage = 0;
    _magicDamage = 5;
    _hpPotion = 10;
    _manaPotion = 10;
    _experience = 0;
    _level = 1;
    _numHPPotions = 0;
    _numManaPotions = 0;
}

fightVictor Player::turn(Monster monster, attackOption choice)
{
    bool isAlive;
    
    switch(choice)
    {
        //normal attack
        case 1:
            isAlive = monster.hit(attack(monster._defense));
            
            if(isAlive)
            {
                return PLAYER;
            }
            break;
        
        //magic attack
        case 2:
            isAlive = monster.hit(_magicDamage);
            decrementMana();
            break;
        //drink HP potion
        case 3:
            drinkHPPotion();
        //drink mana potion
        case 4:
            drinkManaPotion();
            break;
    }
    
    isAlive = hit(monster._attack(_defense));
    
    if(isAlive)
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
    double chanceOfEncouter = 65.0;
    
    bool enemyEncountered = false;
    double randomChanceOfEncounter = 0.0;
    srand(time(0));
    randomChanceOfEncounter = 1 + rand () % 100;
    //cout << randomChanceOfEncounter << endl;
    if(randomChanceOfEncounter > chanceOfEncouter)
        enemyEncountered = true;
    return enemyEncountered;
}

void Player::levelingSystem()//the leveling system for the character
{
    if(this._experience == 100)
    {
        this._level ++;
        this._hitPoints += 10;
        this._attack += 3;
        this._dodge += 3;
        cout << "You are now level " << this._level << "." << endl;
        cout << "Your hit points are now " << this._hitPoints << ", your attack is now " << this._attack << ", your dodge is now " << this._dodge << "." << endl;
        
    }
    
    if(this._experience == 275)
    {
        this._level ++;
        this._hitPoints += 10;
        this._attack += 3;
        this._dodge += 3;
        cout << "You are now level " << this._level << "." << endl;
        cout << "Your hit points are now " << this._hitPoints << ", your attack is now " << this._attack << ", your dodge is now " << this._dodge << "." << endl;
        
    }
    if(this._experience == 475)
    {
        this._level ++;
        this._hitPoints += 10;
        this._attack += 3;
        this._dodge += 3;
        cout << "You are now level " << this._level << "." << endl;
        cout << "Your hit points are now " << this._hitPoints << ", your attack is now " << this._attack << ", your dodge is now " << this._dodge << "." << endl;
    }
    if(this._experience == 600)
    {
        this._level ++;
        this._hitPoints += 10;
        this._attack += 3;
        this._dodge += 3;
        cout << "You are now level " << this._level << "." << endl;
        cout << "Your hit points are now " << this._hitPoints << ", your attack is now " << this._attack << ", your dodge is now " << this._dodge << "." << endl;
        
    }
}

void Player::enemyDrop (Monster monster)//function for generating what items an enemy drops when killed
{
    this._experience += monster._experience;
    cout << "You got " << monster._experience << " experience points." << endl;
    levelingSystem();
    
    int baseEnemyDropPercentage = 35;
    int randomEnemyDropPercentage = 0;
    
    int numPotions = 0;
    int potionDropPercentage = 70;
    int randomPotionDropPercentage = 0;
    
    int numCoins = 0;
    int coinDropPercentage = 30;
    int randomCoinDropPercentage = 0;
    
    srand(time(0));
    randomEnemyDropPercentage = 1 + rand() % 100;
    //cout << "Random enemy drop percentage is " << randomEnemyDropPercentage << endl;
    if(randomEnemyDropPercentage > baseEnemyDropPercentage)
    {
        srand(time(0));
        randomPotionDropPercentage = 1 + rand() % 100;
        if(randomPotionDropPercentage > potionDropPercentage)
        {
            cout << "You got a potion!" << endl;
            this.addPotion(numPotions);
            
        }
        srand(time(0));
        randomCoinDropPercentage = 1 + rand() % 100;
        if(randomCoinDropPercentage > coinDropPercentage)
        {
            srand(time(0));
            numCoins = 1 + rand() % 10;
            cout << "You got " << numCoins << " coins." << endl;
            this.addCoins(numCoins);
        }
    }
    
}

void Player::treasureChest()//randomly generates chests for the player to find
{
    //cout << "Called the treasure chest function" << endl;
    int baseChanceOfChest = 50;
    srand(time(0));
    int randomChanceOfChest = 1 + rand() % 100;
    
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
            srand(time(0));
            randomPotionDropPercentage = 1 + rand() % 100;
            if(randomPotionDropPercentage > potionDropPercentage)
            {
                cout << "You got a potion!" << endl;
                numPotions ++;
                player.addPotion(numPotions);
                playerMenu();
                
            }
            srand(time(0));
            randomCoinDropPercentage = 1 + rand() % 100;
            if(randomCoinDropPercentage > coinDropPercentage)
            {
                srand(time(0));
                numCoins = 1 + rand() % 10;
                cout << "You got " << numCoins << " coins." << endl;
                this.addCoins(numCoins);
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
    int randomDescription;
    srand(time(0));
    randomDescription = 1 + rand() % 10;
    switch(randomDescription)
    {
        case 1:
            cout << "You move deeper into the gloom, with a growing sense of unease." << endl;
            break;
        case 2:
            cout << "As you take another step, you wonder how long this labyrinth could be, and what awaits you deeper inside." << endl;
            break;
        case 3:
            cout << "The air is cold and damp, and the floor slick.  Something brushes your cheek, which after frantic waving of your hands you realize is just a spider's web." << endl;
            break;
        case 4:
            cout << "The walls of the passageway have a faint glow, which upon closer inspection you discover is because of luminescent fungus." << endl;
            break;
        case 5:
            cout << "Something crunches under your foot.  In the faint light you can make out bones, but they don't look like any kind of bones you've ever seen before." << endl;
            break;
        case 6:
            cout << "A sudden sound pierces the dead silence.  It's a scream, but not human.  It's high pitched and trails off into a groan before ending suddenly." << endl;
            break;
        case 7:
            cout << "You slip on something but manage not to fall.  You decide it's better not to see what it was." << endl;
            break;
        case 8:
            cout << "Despite the cold, you're sweating.  You feel your sweat trickling down your back and sides." << endl;
            break;
        case 9:
            cout << "You wonder if you'll ever get out of here.  You find yourself thinking of home, your friends and family." << endl;
            break;
        case 10:
            cout << "The only thing you hear is a faint dripping sound in the distance." << endl;
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

int Player::getPotions()
{
    return _potions;
}

void Player::setPotions(int potions)
{
    _potions = potions;
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
     _hitPoints = _hpPotion;
    
    if(_hitPoints > _maxHitPoints)
    {
        _hitPoints = _maxHitPoints;
    }
    subtractHPPotion();
}
void Player::drinkManaPotion()
{
    _mana = _manaPotion;
    
    if(_mana > _maxMana)
    {
        _mana = _maxMana;
    }
    subtractManaPotions();
}

void Player::decrementMana()
{
    _mana -= 1;
}

