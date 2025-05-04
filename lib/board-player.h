#ifndef BOARD_PLAYER_H
#define BOARD_PLAYER_H

#include <vector>

class BoardPlayer {
  std::vector<std::vector<int>> board;

 public:
  static const int HOUSE_VISIBLE_CLOSED = 0;
  static const int HOUSE_VISIBLE_OPENED = 1;
  static const int HOUSE_VISIBLE_MARKED = 2;

  BoardPlayer(int lengthBoard = 0);

  void toggleMarkHouse(int x, int y);
  void showHouse(int x, int y);
  bool isOpened(int x, int y);
  bool isMarked(int x, int y);
  bool isClosed(int x, int y);
  std::vector<std::vector<int>> getBoard();
};

#endif
