#include "board-player.h"

#include <vector>

#include "board.h"

BoardPlayer::BoardPlayer(int lengthBoard) : board(lengthBoard, std::vector<int>(lengthBoard)) {}

void BoardPlayer::toggleMarkHouse(int x, int y) {
  if (isClosed(x, y)) {
    board[x][y] = HOUSE_VISIBLE_MARKED;
  } else if (isMarked(x, y)) {
    board[x][y] = HOUSE_VISIBLE_CLOSED;
  }
}

void BoardPlayer::showHouse(int x, int y) {
  board[x][y] = HOUSE_VISIBLE_OPENED;
}

bool BoardPlayer::isOpened(int x, int y) {
  return board[x][y] == HOUSE_VISIBLE_OPENED;
}

bool BoardPlayer::isMarked(int x, int y) {
  return board[x][y] == HOUSE_VISIBLE_MARKED;
}

bool BoardPlayer::isClosed(int x, int y) {
  return board[x][y] == HOUSE_VISIBLE_CLOSED;
}

const board_t& BoardPlayer::getBoard() {
  return board;
}
