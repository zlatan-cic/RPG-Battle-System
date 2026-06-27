#include "Mage.h"
#include <iostream>

Mage::Mage(std::string name, int hp, int attackPower, int mana, int magicShield)
          : Character(name,hp,attackPower), mana(mana), magicShield(magicShield) {};

void Mage::attack(Character& target)
{

  if(mana > 0)
  {
    int damage = attackPower * 1.2 - target.getDefence();
    mana -= 20;
    target.takeDamage(damage);
    std::cout << name << " casts spell on " << target.getName() 
          << " for " << damage << " damage!\n";
  } else
  {
    int damage = attackPower;
    target.takeDamage(damage);
    std::cout << name << " attacks " << target.getName() 
          << " for " << damage << " damage! (no mana)\n";
  }
}

void Mage::update(Character& target)
{
  attack(target);
}


void Mage::printStatus()
{
    std::cout << name << " | HP: " << hp << " | Mana: " << mana << "\n";
}

int Mage::getMana()
{
  return mana;
}

int Mage::getMagicShield()
{
  return magicShield;
}