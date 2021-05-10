#ifndef RANGE_H
#define RANGE_H

#include <iostream>
#include <vector>
#include <cmath>

#include "notes.hpp"

class Range {
    private:
        std::vector<unsigned char> m_notes;

    public: 
        Range(Note note, int mode) {
            std::vector<unsigned int> intervals;

            std::vector<unsigned int> i_major{ 2, 2, 1, 2, 2, 2};
            std::vector<unsigned int> i_minor{ 2, 1, 2, 2, 1, 2};

            if(mode) intervals = i_major;
            else intervals = i_minor;

            int current_note = note; 
            m_notes.push_back( current_note );
            for (int i = 0; i < intervals.size(); i++)
            {
        
                current_note += intervals[i];
                std::cout << current_note << std::endl;
                m_notes.push_back( current_note );
            }

            std::cout << "range size : " << m_notes.size() << std::endl;

        }

        unsigned char get_note(int, int);
};

#endif