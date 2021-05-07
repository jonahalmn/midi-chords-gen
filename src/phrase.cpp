#include "../include/phrase.hpp"

std::vector<unsigned int> Phrase::generate_phrase() {
    std::vector<unsigned int> notes;

    notes.push_back(0);
    notes.push_back(-1);
    notes.push_back(0);
    notes.push_back(-1);

    notes.push_back(5);
    notes.push_back(3);
    notes.push_back(0);
    notes.push_back(3);

    return notes;
}