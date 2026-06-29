#include "Player.h"
#include <iostream>

Player::Player(std::string name, int score) :
          name{name}, score{score} {};

std::string Player::getName()
{
  return name;
}

int Player::getScore()
{
  return score;
}

void Player::display()
{
  std::cout << "Players name: " << name << " Score: " << score << '\n';
}

Player::~Player(){};