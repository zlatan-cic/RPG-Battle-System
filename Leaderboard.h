#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include "Player.h"

class Leaderboard
{
  private:
  std::vector<std::unique_ptr<Player>> players;

  public:
  void addPlayer(std::unique_ptr<Player> player);
  void saveFile(const std::string& filename);
  void loadFile(const std::string& filename);
  void removePlayer(std::string name);
  void displaySorted();


};

