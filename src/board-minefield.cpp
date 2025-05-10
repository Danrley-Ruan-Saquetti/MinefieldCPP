#include "board-minefield.h"

#include <random>
#include <vector>

#include "board.h"
#include "utils.h"

BoardMinefield::BoardMinefield(int lengthBoard, int amountBombs)
    : lengthBoard(lengthBoard),
      amountBombs(amountBombs),
      board(lengthBoard, std::vector<int>(lengthBoard)) {}

void BoardMinefield::loadBoard(int excludeX, int excludeY) {
  loadBombs(excludeX, excludeY);
  loadNumbers();
}

void BoardMinefield::loadBombs(int excludeX, int excludeY) {
  std::random_device rd;
  std::mt19937 mt(rd());

  std::uniform_int_distribution random(0, lengthBoard - 1);

  int amountBombsRest = amountBombs;

  while (amountBombsRest > 0) {
    int x = random(rd);
    int y = random(rd);

    if (isBomb(x, y) || (x == excludeX && y == excludeY)) {
      continue;
    }

    board[x][y] = BoardMinefield::HOUSE_BOMB;
    amountBombsRest--;
  }
}

void BoardMinefield::loadNumbers() {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      if (!isBomb(i, j)) {
        continue;
      }

      iterateAround([&](int deltaX, int deltaY) {
        int x = i + deltaX;
        int y = j + deltaY;

        if (x < 0 || y < 0 || x >= board.size() || y >= board[i].size()) {
          return;
        }

        if (!isBomb(x, y)) {
          board[x][y]++;
        }
      });
    }
  }
}

bool BoardMinefield::isBomb(int x, int y) {
  return board[x][y] == BoardMinefield::HOUSE_BOMB;
}

int BoardMinefield::getHouse(int x, int y) {
  return board[x][y];
}

const std::vector<int>& BoardMinefield::operator[](int indexLine) const {
  return board[indexLine];
}

const board_t& BoardMinefield::getBoard() {
  return board;
}
