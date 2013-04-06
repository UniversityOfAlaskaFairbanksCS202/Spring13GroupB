//
//  Character.h
//  Character
//
//  Created by RX-78 01 on 3/26/13.
//  Copyright (c) 2013 lilongyue. All rights reserved.
//

#ifndef __Character__Character__
#define __Character__Character__

#include <iostream>

class Character
{
protected:
    int _hitPoints, _maxHitPoints, _level, _attack, _defense, _weaponDamage, _weaponLevel;
    
public:
    bool hit (int hitPoints);//setter function for changing hit points in fight function
    int defense();//getter method for getting defense used in fight function
    int attack(int defense);//returns hit points to take off of player/monster, if negative, then miss
    int getHitPoints();
    void setHipPoints(int hp);
    int getLevel();
    void setLevel(int level);
    int getAttack();
    void setAttack(int attack);
    int getDefense();
    void setDefense(int defense);
    int getWeaponDamage();
    void setWeaponDamage(int damage);
    int getWeaponLevel();
    void setWeaponLevel(int weaponLevel);


};

#endif /* defined(__Character__Character__) */
