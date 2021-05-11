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
        RtMidiIn *m_midiin = 0;
        std::vector<unsigned char> m_message{0,0,0};
        Range m_range{Note::A, 1};
        std::vector<unsigned int> m_pressed;

    public:
        Player(void(double, std::vector< unsigned char >*, void*));
        void display_available_out_devices();
        void display_available_in_devices();

        void play_chord(int, int, int);
};

#endif