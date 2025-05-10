#include "ui-game.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "board.h"
#include "game.h"

using namespace std;

UIGame::UIGame(Game& game) : game(game) {}

void UIGame::writeMenuInitial() {
  cout << endl
       << "+- Minefield" << endl
       << "| 0 - Exit" << endl
       << "| 1 - Play" << endl
       << "+-" << endl;
}

void UIGame::writeMenuDifficulty() {
  cout << endl
       << "+- Difficulty" << endl
       << "| 0 - Fast Play" << endl
       << "| 1 - Ease" << endl
       << "| 2 - Medium" << endl
       << "| 3 - hard" << endl
       << "+-" << endl;
}

void UIGame::writeBoard(bool isShowHouseHidden) {
  const board_t& board = game.getBoardMinefield();

  cout << endl
       << string(3, ' ');
  for (int i = 1; i <= board.size(); i++) {
    cout << "  " << left << setw(2) << i;
  }
  cout << endl;

  for (int i = 0; i < board.size(); i++) {
    cout << string(3, ' ') << string(board[i].size() * 4 + 1, '-') << endl;

    cout << left << setw(3) << (i + 1);

    for (int j = 0; j < board[i].size(); j++) {
      string house = " ";

      if (game.isOpened(i, j) || isShowHouseHidden) {
        house = formatHouse(board[i][j]);
      } else if (game.isMarked(i, j)) {
        house = "!";
      }

      cout << "| " << house << " ";
    }

    cout << "|" << endl;
  }

  cout << string(3, ' ') << string(board[0].size() * 4 + 1, '-') << endl;
}

string UIGame::formatHouse(int value) {
  switch (value) {
  case -1:
    return "X";
  case 0:
    return "_";
  default:
    return to_string(value);
  }
}
