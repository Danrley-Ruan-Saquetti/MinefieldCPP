#ifndef UTILS_H
#define UTILS_H

#include <functional>
#include <string>
#include <vector>

void iterateAround(std::function<void(int, int)> cal);

std::vector<std::string> split(const std::string& str, char delimiter);

#endif
