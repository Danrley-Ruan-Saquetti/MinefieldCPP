#include "game.h"

#include <iostream>

#include "board-player.h"
#include "utils.h"

Game::Game(int difficulty) {
  lengthBoard = getLengthBoardFromDifficulty(difficulty);
  amountBombs = getAmountBombsBoardFromDifficulty(difficulty);

  boardMinefield = BoardMinefield(lengthBoard, amountBombs);
  boardPlayer = BoardPlayer(lengthBoard);
}

int Game::getLengthBoardFromDifficulty(int difficulty) {
  switch (difficulty) {
  case 0:
    return 5;
  case 1:
    return 9;
  case 2:
    return 16;
  case 3:
    return 22;
  default:
    return 10;
  };
}

int Game::getAmountBombsBoardFromDifficulty(int difficulty) {
  switch (difficulty) {
  case 0:
    return 5;
  case 1:
    return 10;
  case 2:
    return 40;
  case 3:
    return 90;
  default:
    return 10;
  };
}

void Game::loadBoard(int firstHouseOpenedX, int firstHouseOpenedY) {
  boardMinefield.loadBoard(firstHouseOpenedX, firstHouseOpenedY);
  amountHousesSecurity = calcAmountHousesSecurity();

  playing = true;
  winner = false;

  openHouse(firstHouseOpenedX, firstHouseOpenedY);
}

void Game::performPlayerMove(PlayerMove playerMove) {
  if (playerMove.isMark) {
    toggleMarkHouse(playerMove.x, playerMove.y);
  } else {
    openHouse(playerMove.x, playerMove.y);
  }
}

int Game::calcAmountHousesSecurity() {
  return (lengthBoard * lengthBoard) - amountBombs;
}

bool Game::isAllHousesVisible() {
  return amountHousesSecurity <= 0;
}

bool Game::isOpened(int x, int y) {
  return boardPlayer.isOpened(x, y);
}

bool Game::isMarked(int x, int y) {
  return boardPlayer.isMarked(x, y);
}

bool Game::isClosed(int x, int y) {
  return boardPlayer.isClosed(x, y);
}

bool Game::isPlaying() {
  return playing;
}

bool Game::isWinner() {
  return winner;
}

int Game::getLengthBoard() {
  return lengthBoard;
}

std::vector<std::vector<int>> Game::getBoardMinefield() {
  return boardMinefield.getBoard();
}

std::vector<std::vector<int>> Game::getBoardPlayer() {
  return boardPlayer.getBoard();
}

void Game::openHouse(int x, int y) {
  if (boardPlayer.isMarked(x, y)) {
    return;
  }

  if (boardMinefield.isBomb(x, y)) {
    showHouse(x, y);
    lose();
  } else {
    openHouses(x, y);

    if (isAllHousesVisible()) {
      win();
    }
  }
}

void Game::openHouses(int x, int y) {
  if (!boardPlayer.isClosed(x, y)) {
    return;
  }

  showHouse(x, y);

  if (boardMinefield.getHouse(x, y) > 0) {
    return;
  }

  iterateAround([&](int deltaX, int deltaY) {
    int xBoard = x + deltaX;
    int yBoard = y + deltaY;

    if (xBoard < 0 || yBoard < 0 || xBoard > lengthBoard || yBoard > lengthBoard) {
      return;
    }

    if (boardPlayer.isClosed(xBoard, yBoard)) {
      openHouses(xBoard, yBoard);
    }
  });
}

void Game::toggleMarkHouse(int x, int y) {
  boardPlayer.toggleMarkHouse(x, y);
}

void Game::win() {
  playing = false;
  winner = true;
}

void Game::lose() {
  playing = false;
  winner = false;
}

void Game::showHouse(int x, int y) {
  boardPlayer.showHouse(x, y);
  amountHousesSecurity--;
}
