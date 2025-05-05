#include <iostream>
#include <limits>
#include <string>

#include "game.h"
#include "player-move.h"
#include "ui-game.h"
#include "utils.h"

using namespace std;

PlayerMove* readPlayerMove(int lengthBoard) {
  int x, y;

  cout << "$ X: ";
  cin >> x;

  cout << "$ Y: ";
  cin >> y;

  if (x <= 0 || y <= 0 || x >= lengthBoard || y >= lengthBoard) {
    cout << "Invalid action" << endl;
    return nullptr;
  }

  return new PlayerMove(x - 1, y - 1, false);
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

    PlayerMove* playerMove = nullptr;

    do {
      uiGame.writeBoard();
      playerMove = readPlayerMove(game.getLengthBoard());
    } while (!playerMove);

    game.loadBoard(playerMove->x, playerMove->y);

    do {
      uiGame.writeBoard();
      playerMove = readPlayerMove(game.getLengthBoard());

      if (playerMove != nullptr) {
        game.performPlayerMove(*playerMove);
      }
    } while (game.isPlaying());

    delete playerMove;

    uiGame.writeBoard(true);

    if (game.isWinner()) {
      cout << "Winner" << endl;
    } else {
      cout << "Game Over" << endl;
    }
  } while (option != 0);

  return 0;
}
