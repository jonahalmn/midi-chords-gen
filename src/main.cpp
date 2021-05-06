#include <iostream>
#include <vector>
#include <string>
#include <CoreMIDI/CoreMIDI.h>
#include <CoreFoundation/CFRunLoop.h>
#include <rtmidi.h>

#define PACKETLIST_SIZE 512

int main() {

    std::cout << "All is ok" << std::endl;
    RtMidiOut *midiout = 0;


    // RtMidiOut constructor
    try {
        midiout = new RtMidiOut();
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
        exit( EXIT_FAILURE );
    }
    // Check outputs.
    unsigned int nPorts = midiout->getPortCount();
    std::cout << "\nThere are " << nPorts << " MIDI output ports available.\n";
    std::string portName;
    for ( unsigned int i=0; i<nPorts; i++ ) {
        try {
        portName = midiout->getPortName(i);
        }
        catch (RtMidiError &error) {
        error.printMessage();
        goto cleanup;
        }
        std::cout << "  Output Port #" << i+1 << ": " << portName << '\n';
    }
    std::cout << '\n';

    cleanup:
        delete midiout;

    return 0;
}