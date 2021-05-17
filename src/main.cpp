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


bool midi_clock = false;

void mycallback( double deltatime, std::vector< unsigned char > *message, void *userData )
{
  unsigned int nBytes = message->size();
  if((*message)[1] == (unsigned char)60 && (*message)[0] == (unsigned char)144) {
    midi_clock = true;
  }
  // for ( unsigned int i=0; i<nBytes; i++ )
  //   // std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  // if ( nBytes > 0 )
    // std::cout << "stamp = " << deltatime << std::endl;
}

int main(int argc, char *argv[] ) {

    Player player{&mycallback};
    Phrase phrase;

    std::vector<std::vector<unsigned int>> current_phrase = phrase.generate_phrase();
  

    unsigned int i = 0;
    unsigned int delta_time = 10000;

    while (1)
    {
      if(midi_clock) { 
        midi_clock = false;
        std::cout << "CLOCK" << std::endl;
        std::cout << "duration: " << current_phrase[i][2] << std::endl;
        delta_time++;

        if(delta_time > current_phrase[i][2] - 1) {
          i = (i + 1) % current_phrase.size();
          player.play_chord(current_phrase[i][0], 3, current_phrase[i][1]);
          delta_time = 0;
        }

        if(i == 0) current_phrase = phrase.generate_phrase();
      }
    }


    return 0;
}