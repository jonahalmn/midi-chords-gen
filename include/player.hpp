#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <CoreMIDI/CoreMIDI.h>
#include <CoreFoundation/CFRunLoop.h>
#include <rtmidi.h>

#include "range.hpp"
#include "notes.hpp"
#include "phrase.hpp"

class Player {
    protected:
        RtMidiOut *m_midiout = 0;
        RtMidiIn *m_midiin = 0;
        std::vector<unsigned char> m_message{0,0,0};
        Range m_range{Note::A, 0};
        std::vector<std::vector<unsigned int>> m_pressed;

        Player();

        static unsigned int s_current_time;
        static unsigned int s_note_time;
        static Player *s_player;
        static std::vector<std::vector<unsigned int>> s_current_phrase;
        static Phrase s_phrase;

    public:
        void display_available_out_devices();
        void display_available_in_devices();

        void play_chord(int, int, int, unsigned int);

        static Player* get_instance();
        static void on_midi( double deltatime, std::vector< unsigned char > *message, void *userData);
};

#endif