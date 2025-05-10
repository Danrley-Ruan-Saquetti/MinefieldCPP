#ifndef UI_GAME_H
#define UI_GAME_H

#include <iostream>
#include <string>

#include "game.h"

class UIGame {
  Game& game;

 public:
  UIGame(Game& game);

  static void writeMenuInitial();
  static void writeMenuDifficulty();
  static std::string formatHouse(int value);

  void writeBoard(bool isShowHouseHidden = false);
};

#endif
