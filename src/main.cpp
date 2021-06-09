#include <CoreFoundation/CFRunLoop.h>
#include <CoreMIDI/CoreMIDI.h>
#include <fstream>
#include <iostream>
#include <rtmidi.h>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "../include/phrase.hpp"
#include "../include/player.hpp"

#define PACKETLIST_SIZE 512

int main(int argc, char *argv[]) {

  Player *player = Player::get_instance();

  unsigned int i = 0;
  unsigned int delta_time = 10000;

  while (1) {
  }

  return 0;
}