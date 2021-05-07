#include "../include/player.hpp"

Player::Player(void(callback)(double, std::vector< unsigned char >*, void*) ) {
    // RtMidiOut constructor
    try {
        m_midiout = new RtMidiOut();
        m_midiin = new RtMidiIn();
        display_available_out_devices();
        m_midiout->openPort( 1 );
        m_midiin->openPort( 0 );

        // Set our callback function.  This should be done immediately after
        // opening the port to avoid having incoming messages written to the
        // queue.
        m_midiin->setCallback( callback );
        // Don't ignore sysex, timing, or active sensing messages.
        m_midiin->ignoreTypes( false, false, false );
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
        exit( EXIT_FAILURE );
    }
}

void Player::display_available_out_devices() {
        // Check outputs.
    unsigned int nPorts = m_midiout->getPortCount();
    std::cout << "\nThere are " << nPorts << " MIDI output ports available.\n";
    std::string portName;
    for ( unsigned int i=0; i<nPorts; i++ ) {
        try {
        portName = m_midiout->getPortName(i);
        }
        catch (RtMidiError &error) {
            error.printMessage();
            delete m_midiout;
            exit(EXIT_FAILURE);
        }
        std::cout << "  Output Port #" << i+1 << ": " << portName << '\n';
    }
    std::cout << '\n';
}

void Player::display_available_in_devices() {
        // Check outputs.
    unsigned int nPorts = m_midiout->getPortCount();
    std::cout << "\nThere are " << nPorts << " MIDI output ports available.\n";
    std::string portName;
    for ( unsigned int i=0; i<nPorts; i++ ) {
        try {
        portName = m_midiout->getPortName(i);
        }
        catch (RtMidiError &error) {
            error.printMessage();
            delete m_midiout;
            exit(EXIT_FAILURE);
        }
        std::cout << "  Output Port #" << i+1 << ": " << portName << '\n';
    }
    std::cout << '\n';
}

void Player::play_chord(int note, int octave, int number) {
    m_message[2] = 90;
    
    // Note On
    m_message[0] = 144;
    for (int i = 0; i < number; i++)
    {
        m_message[1] = (unsigned int)m_range.get_note(note + i * 2, octave);
        m_midiout->sendMessage( &m_message );
    }

    sleep(0.3);

    // Note Off
    m_message[0] = 128;
    for (int i = 0; i < number; i++)
    {
        m_message[1] = (unsigned int)m_range.get_note(note + i * 2, octave);
        m_midiout->sendMessage( &m_message );
    }


}