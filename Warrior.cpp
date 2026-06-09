#include "Warrior.h"
#include <iostream>

Warrior::Warrior(std::string name, int hp, int attackPower, int armor)
: Character(name,hp,attackPower), armor(armor) {}

int Warrior::getArmor()
{
  return armor;
}

void Warrior::attack(Character& target)
{
  int damage = attackPower * 1.5 - target.getDefence();
  target.takeDamage(damage);
  std::cout << name << " Attack " << target.getName() 
          << " " << damage << " damage!\n";
}

void Warrior::printStatus()
{
  std::cout << name << " | HP: " << hp << '\n';
}
