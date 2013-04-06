//
//  Player.h
//  Character
//
//  Created by RX-78 01 on 3/26/13.
//  Copyright (c) 2013 lilongyue. All rights reserved.
//

#ifndef __Character__Player__
#define __Character__Player__

#include <iostream>
#include "Character.h"
#include "Monster.h"

class Player: public Character
{
private:
    int _mana, _maxMana, experience, _numHPPotions, _numManaPotions, _coins, _magicDamage, _hpPotion, _manaPotion;
    
public:
    enum fightVictor = {NEITHER, PLAYER, MONSTER};
    enum attackOption = {ATTACK, MAGICATTACK, DRINKHP, DRINKMANA};
    Player();
    fightVictor turn(Monster monster, attackOption choice);
    bool randomEncounter();
    void levelingSystem();
    void enemyDrop (Monster monster);
    void treasureChest();
    void movementDescription();
    void magicAttack();
    void addHPPotion(int numHPPotions);
    void addManaPotion(int numManaPotions);
    void subtractHPPotion();
    void subtractManaPotions();
    void drinkHPPotion();
    void drinkManaPotion();
    void decrementMana();
    
    int getMana();
    void setMana(int mana);
    int getMaxMana();
    void setMaxMana(int maxMana);
    int getExperience();
    void setExperience(int exp);
    int getPotions();
    void setPotions(int potions);
    int getCoins();
    void setCoins(int coins);
    
};

#endif /* defined(__Character__Player__) */
