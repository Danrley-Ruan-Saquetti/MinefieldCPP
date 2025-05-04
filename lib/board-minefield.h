#ifndef BOARD_MINEFIELD_H
#define BOARD_MINEFIELD_H

#include <vector>

class BoardMinefield {
  int lengthBoard;
  int amountBombs;

  std::vector<std::vector<int>> board;

 public:
  static const int HOUSE_BOMB = -1;

  BoardMinefield(int length = 0, int amountBombs = 0);

  void loadBoard(int excludeX = -1, int excludeY = -1);
  void reset();
  bool isBomb(int x, int y);
  int getHouse(int x, int y);
  std::vector<std::vector<int>> getBoard();

 private:
  void loadBombs(int excludeX = -1, int excludeY = -1);
  void loadNumbers();
};

#endif
