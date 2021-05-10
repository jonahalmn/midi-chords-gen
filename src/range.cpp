#include "range.hpp"

unsigned char Range::get_note(int note, int octave) {
    if(note > 80 || note < -50) {
        std::cout << "invalid note" << std::endl;
        return 129;
    }

    if(octave < 0 || octave > 8) {
        std::cout << "invalid octave" << std::endl;
        return 129;
    }

    octave += floor(note / 7);

    return (int)m_notes[note % 7] + 12 * octave;
}

