#include <iostream>
#include <vector>
#include <string>
#include <CoreMIDI/CoreMIDI.h>
#include <CoreFoundation/CFRunLoop.h>
#include <rtmidi.h>

#include "../include/player.hpp"
#include "../include/phrase.hpp"

#define PACKETLIST_SIZE 512

int main() {

    // Range range{Note::A, 0};

    // std::cout << (int)range.get_note(0, 2) << std::endl;
    

    std::cout << "All is ok" << std::endl;

    Player player;
    Phrase phrase;

    std::vector<unsigned int> phrase_now = phrase.generate_phrase();

    unsigned int i = 0;

    while (1)
    {
        i = (i + 1) % phrase_now.size();
        player.play_chord(phrase_now[i], 3, 6);
    }


    return 0;
}