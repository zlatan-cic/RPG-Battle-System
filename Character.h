#pragma once

#include <iostream>
#include <string>

class Character
{
  protected:
  std::string name;
  int hp;
  int attackPower;
public:

  Character(std::string name, int hp, int attackPower);
  virtual void attack(Character& target);
  virtual void printStatus();
  bool isAlive();
  std::string getName();
//
  virtual int getDefence();
  void takeDamage(int damage);

//
  virtual void update(Character& target);

  virtual ~Character() {}

};