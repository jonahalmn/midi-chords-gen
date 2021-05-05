#include <iostream>
#include <CoreMIDI/MIDIServices.h>
#include <CoreFoundation/CFRunLoop.h>

MIDIPortRef     gOutPort = NULL;
MIDIEndpointRef gDest = NULL;
int             gChannel = 0;

int main() {

    std::cout << "All is ok" << std::endl;

    // create client and ports
    MIDIClientRef client = NULL;
    MIDIClientCreate(CFSTR("MIDI Echo"), NULL, NULL, &client);

    MIDIPortRef inPort = NULL;
    MIDIInputPortCreate(client, CFSTR("Input port"), MyReadProc, NULL, &inPort);
    MIDIOutputPortCreate(client, CFSTR("Output port"), &gOutPort);

    MIDIEndpointRef epRef = MIDIGetSource(1);



    int n = MIDIGetNumberOfDevices();
    std::cout << n << std::endl;

    return 0;
}