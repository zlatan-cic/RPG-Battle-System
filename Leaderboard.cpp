#include "Leaderboard.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

void Leaderboard::addPlayer(std::unique_ptr<Player> player)
{
  players.push_back(std::move(player));
}

void Leaderboard::removePlayer(std::string name)
{
  auto it = std::find_if(players.begin(), players.end(), [&name]
(const std::unique_ptr<Player> &player)
{
  return player->getName() == name;
});

  if(it != players.end())
  {
    std::string removedName = (*it)->getName();
    int removedScore = (*it)->getScore();

    std::cout << "Player: " << removedName << " with score: " 
               << removedScore << " was removed!\n";
    players.erase(it);
  }
  else
  {
    std::cout << name << " not found!\n";
  }

}

void Leaderboard::saveFile(const std::string& filename)
{
  std::ofstream file(filename);
  for(const auto& player : players)
  {
    file << player->getName() << '\n';
    file << player->getScore() << '\n';
    // file << "*------------------------*\n";
  }
}

void Leaderboard::loadFile(const std::string& filename)
{
  players.clear(); // important !!
  std::ifstream file(filename); // Only reads file !!!
  std::string name, scoreStr, separator;

  while(std::getline(file,name))
    {

      std::getline(file, scoreStr); // reads score like string
      std::getline(file, separator);

      int score = std::stoi(scoreStr); // string -> int

      players.push_back(std::make_unique<Player>(name, score));
    }
}

void Leaderboard::displaySorted()
{
  std::sort(players.begin(), players.end(),
  [](const auto& a,const auto& b)
{
  return a->getScore() > b->getScore();
});

  for(const auto& player : players)
  {
    player->display();
  }
}