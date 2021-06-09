#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <vector>

class Phrase {
protected:
  std::vector<std::vector<unsigned int>> m_params;
  nlohmann::json m_tree;
  unsigned int m_speed_factor = 8;

public:
  Phrase();

  void populate();
  void set_speed(unsigned int);
  std::vector<std::vector<unsigned int>> generate_phrase();
  std::vector<std::map<unsigned int, std::vector<unsigned int>>>
  generate_drums_phrase();
};