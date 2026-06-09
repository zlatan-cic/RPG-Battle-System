#include <iostream>
#include "Warrior.h"
#include "Mage.h"

void battle(Character& a, Character& b)
{
  while(a.isAlive() && b.isAlive())
  {
    a.attack(b);
    b.printStatus();

    if(!b.isAlive()) break;

    b.attack(a);
    a.printStatus();
  }

  if(a.isAlive())
  {
    std::cout << "\n--- " << a.getName() << " wins! ---\n";
  } else
  {
    std::cout << "\n--- " << b.getName() << " wins! ---\n";
  }
}

int main()
{
  Warrior warrior("Thorin", 100, 20, 10);
  Mage mage("Gandalf", 80, 15, 100, 5);

  battle(warrior, mage);

  return 0;
}