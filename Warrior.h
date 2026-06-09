#pragma once

#include <iostream>
#include "Character.h"

class Warrior:public Character
{
  private:
  int armor;

  public:
  Warrior(std::string name, int hp, int attackPower, int armor);
  
  int getArmor();
  void attack(Character& target) override;
  void printStatus() override;


};