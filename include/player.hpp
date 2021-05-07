#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <CoreMIDI/CoreMIDI.h>
#include <CoreFoundation/CFRunLoop.h>
#include <rtmidi.h>

#include "range.hpp"
#include "notes.hpp"

class Player {
    protected:
        RtMidiOut *m_midiout = 0;
        std::vector<unsigned char> m_message{0,0,0};
        Range m_range{Note::A, 0};

    public:
        Player();
        void display_available_devices();

        void play_chord(int, int, int);
};

#endif