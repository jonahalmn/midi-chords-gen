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
    std::cout << "CLOCK" << std::endl;
  }
  for ( unsigned int i=0; i<nBytes; i++ )
    std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  if ( nBytes > 0 )
    std::cout << "stamp = " << deltatime << std::endl;
}

int main(int argc, char *argv[] ) {

    // Range range{Note::A, 0};
   

    // std::cout << (int)range.get_note(0, 2) << std::endl;
    

    std::cout << "All is ok" << std::endl;

    Player player{&mycallback};
    Phrase phrase;

    std::vector<std::vector<unsigned int>> phrase_now = phrase.generate_phrase();
  

    unsigned int i = 0;

    while (1)
    {
      if(midi_clock) {
        midi_clock = false;
        i = (i + 1) % phrase_now.size();
        player.play_chord(phrase_now[i][0], 3, phrase_now[i][1]);
      }
    }


    return 0;
}