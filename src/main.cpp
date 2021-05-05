#include <iostream>
#include <CoreMIDI/MIDIServices.h>
#include <CoreFoundation/CFRunLoop.h>

int main() {

    std::cout << "All is ok" << std::endl;

    // create client and ports
    MIDIClientRef client = NULL;
    // MIDIClientCreate(CFSTR("MIDI Echo"), NULL, NULL, &client);

    int n = MIDIGetNumberOfDevices();
    std::cout << n << std::endl;

    return 0;
}