#ifndef PLAYER_MOVE_H
#define PLAYER_MOVE_H

struct PlayerMove {
  const int x;
  const int y;
  const bool isMark;

  PlayerMove(int x, int y, bool isMark = false);
};

#endif
