//
//  Character.cpp
//  Character
//
//  Created by RX-78 01 on 3/26/13.
//  Copyright (c) 2013 lilongyue. All rights reserved.
//

#include "Character.h"

bool Character::hit (int hitPoints)
{
    bool isDead = false;
    _hitPoints -= hitPoints;
    if(_hitPoints == 0)
    {
        isDead = true;
        return isDead;
    }
    else
    {
        return isDead;
    }
}

int Character::defense()
{
    return _defense;
}

int Character::attack(int defense)
{
    if(_attack > defense)
    {
        return hit(_weaponDamage);
    }
    else
    {
        return 0;
    }
}

int Character::getHitPoints()
{
    return _hitPoints;
}
void Character::setHipPoints(int hp)
{
    _hitPoints = hp;
    
}

int Character::getLevel()
{
    return _level;
}

void Character::setLevel(int level)
{
    _level = level;
}

int Character::getAttack()
{
    return _attack;
}

void Character::setAttack(int attack)
{
    _attack = attack;
}

int Character::getDefense()
{
    return _defense;
}

void Character::setDefense(int defense)
{
    _defense = defense;
}

int Character::getWeaponDamage()
{
    return _weaponDamage;
}
void Character::setWeaponDamage(int damage)
{
    _weaponDamage = damage;
}

int Character::getWeaponLevel()
{
    return _weaponLevel;
}

void Character::setWeaponLevel(int weaponLevel)
{
    _weaponLevel = weaponLevel;
}








