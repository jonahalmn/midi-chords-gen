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
            // goto cleanup;
            delete midiout;
            exit(EXIT_FAILURE);
        }
        std::cout << "  Output Port #" << i+1 << ": " << portName << '\n';
    }
    std::cout << '\n';

    std::vector<unsigned char> message;
    // Note On: 144, 64, 90
    message.push_back(144);
    message.push_back(64);
    message.push_back(90);

    unsigned int i = 1;
    
    midiout->openPort( 0 );
    
    while (1)
    {

        message[0] = 144;
        message[1] = i;
        midiout->sendMessage( &message );
        i = (i + 1) % 128;

        // std::cout << i << std::endl;
        // std::cout <<  message[1] << std::endl;

        sleep(1);
        // std::cout << "midi sent" << std::endl;
        // // Note Off: 128, 64, 40
        message[0] = 128;
        // message[1] = 64;
        // message[2] = 40;
        midiout->sendMessage( &message );
    }
    

    delete midiout;

    return 0;
}