#include "../include/phrase.hpp"

Phrase::Phrase() {
  // read a JSON file
  std::ifstream file("data/data.json");
  file >> m_tree;

  int user_input = 0;

  while (!user_input) {
    std::cout << "choose a speed factor: ";
    std::cin >> user_input;
    std::cout << std::endl;

    if (user_input < 0 || user_input > 100) {
      std::cout << "invalid factor" << std::endl;
      user_input = 0;
    }
  }

  m_speed_factor = (unsigned int)user_input;

  populate();
}

void Phrase::set_speed(unsigned int speed) { m_speed_factor = speed; }

std::vector<std::vector<unsigned int>> Phrase::generate_phrase() {
  std::vector<std::vector<unsigned int>> notes;
  unsigned int current_state = 0;
  unsigned int filled_times = 0;

  srand((int)time(NULL));

  for (int i = 0; i < 4; i++) {
    notes.push_back(std::vector<unsigned int>{m_params[current_state]});
    int duration;

    if (i == 3) {
      duration = (8 * m_speed_factor) - filled_times;
    } else {
      duration = (floor(rand() % 2) + 1) * m_speed_factor;
      filled_times += duration;
    }

    std::cout << "m_tree.size() : " << m_tree.size() << std::endl;
    std::cout << "current_state : " << current_state << std::endl;
    std::cout << "duration : " << duration << std::endl;

    notes[notes.size() - 1].push_back(duration);

    unsigned int probability =
        (rand() % 1000 *
         (unsigned int)
             m_tree[current_state][m_tree[current_state].size() - 1]) /
        1000;
    unsigned int accumulator = 0;
    unsigned int j = 0;

    for (int k = 0; k < notes[i].size(); k++) {
      std::cout << notes[i][k] << ",";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    do {
      accumulator += (unsigned int)m_tree[current_state][j];
      j++;
    } while (accumulator < probability);

    current_state = j - 1;
  }

  return notes;
}

std::vector<std::map<unsigned int, std::vector<unsigned int>>>
Phrase::generate_drums_phrase() {}

void Phrase::populate() {
  for (unsigned int i = 1; i <= 3; i++) {
    for (unsigned int j = 0; j < 7; j++) {
      m_params.push_back(std::vector<unsigned int>{j, i + 3});
      std::cout << "[ " << j << ";" << i + 2 << " ]" << std::endl;
    }
  }

  std::vector<int> state_prob = m_tree.at(0);
}