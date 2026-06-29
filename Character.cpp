#include "Character.h"
#include <string>

Character::Character(std::string name,int hp, int attackPower)
: name(name), hp(hp), attackPower(attackPower) {}

void Character::attack(Character& target)
{
  // target.hp -= attackPower;
  target.takeDamage(attackPower);
  std::cout << name << " attack " << target.name 
                  << ": " << attackPower << " damage!\n";
}

void Character::printStatus()
{
  std::cout << name << " | HP: " << hp << '\n';
}

bool Character::isAlive()
{
  return hp > 0;
}

std::string Character::getName()
{
  return name;
}

int Character::getDefence()
{
  return 0;
}
///
void Character::update(Character& target)
{
  attack(target);
}

int Character::getHealth()
{
  return hp;
}
void Character::takeDamage(int damage) {
  hp -= damage;
  if(hp < 0) hp = 0;
}