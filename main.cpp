#include <iostream>
#include "Warrior.h"
#include "Mage.h"
#include <memory>
#include "Leaderboard.h"
#include "Player.h"

void battle(Character& a, Character& b, Leaderboard& leaderboard)
{
  
  while(a.isAlive() && b.isAlive())
  {
    a.update(b);
    b.printStatus();

    if(!b.isAlive()) break;

    b.update(a);
    a.printStatus();
  }

  if(a.isAlive())
  {
    std::cout << "\n--- " << a.getName() << " wins! ---\n";
     leaderboard.addPlayer(std::make_unique<Player>(a.getName(), a.getHealth())); 
    
  } else
  {
    std::cout << "\n--- " << b.getName() << " wins! ---\n";
    leaderboard.addPlayer(std::make_unique<Player>(b.getName(), b.getHealth()));
  }
}

int main()
{
  // Warrior warrior("Thorin", 100, 20, 10);
  
  // Mage mage("Gandalf", 80, 15, 100, 5);

  Leaderboard leaderboard;

  std::unique_ptr<Character> warrior = std::make_unique<Warrior>("Thorin", 100,20,10);
  std::unique_ptr<Character> mage = std::make_unique<Mage>("Gandalf", 80,15,100,5);

  battle(*warrior, *mage, leaderboard);

  leaderboard.displaySorted();
  leaderboard.saveFile("results.txt");

  return 0;
}