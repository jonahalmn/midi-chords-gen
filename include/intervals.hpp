#ifndef INTERVALS_H
#define INTERVALS_H

#include <vector>

class Intervals {
public:
  static std::vector<unsigned int> major;
  static std::vector<unsigned int> minor;
};

std::vector<unsigned int> Intervals::major = {2, 2, 1, 2, 2, 2};
std::vector<unsigned int> Intervals::minor = {2, 1, 2, 2, 1, 2};

#endif