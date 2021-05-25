#include <iostream>
#include <vector>
#include <string>
#include <CoreMIDI/CoreMIDI.h>
#include <CoreFoundation/CFRunLoop.h>
#include <rtmidi.h>
#include <fstream>

#include <nlohmann/json.hpp>

#include "../include/player.hpp"
#include "../include/phrase.hpp"

#define PACKETLIST_SIZE 512

int main(int argc, char *argv[] ) {

    Player *player = Player::get_instance();

    unsigned int i = 0;
    unsigned int delta_time = 10000;

    while (1) {}

    return 0;
}