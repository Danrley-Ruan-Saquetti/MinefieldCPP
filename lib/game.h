#ifndef GAME_H
#define GAME_H

#include <vector>

#include "board-minefield.h"
#include "board-player.h"
#include "board.h"
#include "player-move.h"

class Game {
  BoardMinefield boardMinefield;
  BoardPlayer boardPlayer;

  int lengthBoard{};
  int amountBombs{};

  bool playing{};
  bool winner{};

  int amountHousesSecurity{};

 public:
  Game(int difficulty);

 private:
  int static getLengthBoardFromDifficulty(int difficulty);
  int static getAmountBombsBoardFromDifficulty(int difficulty);

 public:
  void loadBoard(int firstHouseOpenedX = -1, int firstHouseOpenedY = -1);
  void performPlayerMove(PlayerMove playerMove);
  int calcAmountHousesSecurity();
  bool isAllHousesVisible();
  bool isOpened(int x, int y);
  bool isMarked(int x, int y);
  bool isClosed(int x, int y);
  bool isPlaying();
  bool isWinner();
  int getLengthBoard();
  const board_t& getBoardMinefield();
  const board_t& getBoardPlayer();

 private:
  void openHouse(int x, int y);
  void openHouses(int x, int y);
  void toggleMarkHouse(int x, int y);
  void win();
  void lose();
  void showHouse(int x, int y);
};

#endif
