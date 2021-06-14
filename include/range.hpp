#ifndef RANGE_H
#define RANGE_H

#include <cmath>
#include <iostream>
#include <vector>

#include "notes.hpp"

class Range {
private:
  std::vector<unsigned char> m_notes;
  Note m_fundamental;

  std::vector<unsigned int> m_intervals;

  std::vector<unsigned int> m_i_major{2, 2, 1, 2, 2, 2};
  std::vector<unsigned int> m_i_minor{2, 1, 2, 2, 1, 2};

public:
  Range(Note fundamental, int mode) {
    if (mode)
      m_intervals = m_i_major;
    else
      m_intervals = m_i_minor;

    m_fundamental = fundamental;
    int current_note = m_fundamental;
    m_notes.push_back(current_note);
    for (int i = 0; i < m_intervals.size(); i++) {

      current_note += m_intervals[i];
      // std::cout << current_note << std::endl;
      m_notes.push_back(current_note);
    }

    std::cout << "range size : " << m_notes.size() << std::endl;
  }

  unsigned char get_note(int, int);
  void set_fundamental(Note);
  Note get_fundamental();
};

#endif