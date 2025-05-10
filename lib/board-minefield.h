#ifndef BOARD_MINEFIELD_H
#define BOARD_MINEFIELD_H

#include <vector>

#include "board.h"

class BoardMinefield {
  int lengthBoard{};
  int amountBombs{};

  board_t board;

 public:
  static const int HOUSE_BOMB = -1;

  BoardMinefield(int length = 0, int amountBombs = 0);

  void loadBoard(int excludeX = -1, int excludeY = -1);
  bool isBomb(int x, int y);
  int getHouse(int x, int y);
  const board_t& getBoard();

 private:
  void loadBombs(int excludeX = -1, int excludeY = -1);
  void loadNumbers();
};

#endif
