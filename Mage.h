#pragma once

#include "Character.h"

class Mage:public Character
{
  private:
  int mana;
  int magicShield;

  public:
  Mage(std::string name, int hp, int attackPower, int mana, int magicShield);
  void attack(Character& target) override;
  void printStatus() override;

  int getMana();
  int getMagicShield();

};