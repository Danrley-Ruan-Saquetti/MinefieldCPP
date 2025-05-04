#include <iostream>
#include <limits>
#include <string>

#include "game.h"
#include "player-move.h"
#include "ui-game.h"
#include "utils.h"

using namespace std;

PlayerMove* readPlayerMove() {
  string inputPlayerMove;
  cout << endl
       << "$ ";
  getline(cin, inputPlayerMove);

  vector<string> inputPlayerMoveArgs = split(inputPlayerMove, ' ');

  int x,
      y;
  bool isMark = false;
  try {
    switch (inputPlayerMoveArgs.size()) {
    case 2:
      x = stoi(inputPlayerMoveArgs[0]) - 1;
      y = stoi(inputPlayerMoveArgs[1]) - 1;

      break;
    case 3:
      x = stoi(inputPlayerMoveArgs[1]) - 1;
      y = stoi(inputPlayerMoveArgs[2]) - 1;

      if (inputPlayerMoveArgs[0] == "!") {
        isMark = true;
      }

      break;
    default:
      cout << "Invalid command" << endl;
      return nullptr;
    }
  } catch (const runtime_error& e) {
    cout << "Invalid command" << endl;
    return nullptr;
  }

  cout << "X: " << x << ", Y: " << y;

  PlayerMove* playerMove = new PlayerMove(x, y, isMark);

  return playerMove;
}

int main() {
  int option;

  do {
    UIGame::writeMenuInitial();
    cout << "$ ";
    cin >> option;

    if (option == 0) {
      continue;
    }

    int difficulty;
    UIGame::writeMenuDifficulty();
    cout << "$ ";
    cin >> difficulty;

    Game game(difficulty);
    UIGame uiGame(game);

    PlayerMove* playerMove;

    do {
      uiGame.writeBoard();
      playerMove = readPlayerMove();
    } while (playerMove == nullptr);

    game.loadBoard(playerMove->x, playerMove->y);

    do {
      uiGame.writeBoard();
      playerMove = readPlayerMove();

      if (playerMove != nullptr) {
        game.performPlayerMove(*playerMove);
      }
    } while (game.isPlaying());

    uiGame.writeBoard(true);

    if (game.isWinner()) {
      cout << "Winner" << endl;
    } else {
      cout << "Game Over" << endl;
    }
  } while (option != 0);

  return 0;
}
