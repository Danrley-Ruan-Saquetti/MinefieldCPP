#include "utils.h"

#include <sstream>
#include <string>
#include <vector>

void iterateAround(std::function<void(int, int)> callback) {
  for (int deltaX = -1; deltaX < 2; deltaX++) {
    for (int deltaY = -1; deltaY < 2; deltaY++) {
      if (deltaX == 0 && deltaX == deltaY) {
        continue;
      }

      callback(deltaX, deltaY);
    }
  }
}

std::vector<std::string> split(const std::string& str, char delimiter) {
  std::vector<std::string> tokens;
  std::stringstream ss(str);
  std::string token;

  while (std::getline(ss, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}
