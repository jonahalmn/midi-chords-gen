#include "../include/player.hpp"

Player *Player::s_player;
unsigned int Player::s_current_time = 0;
unsigned int Player::s_note_time = 10000;
Phrase Player::s_phrase;
std::vector<std::vector<unsigned int>> Player::s_current_phrase = Player::s_phrase.generate_phrase();

Player::Player() {
    // m_current_phrase = m_phrase.generate_phrase();

    try {
        m_midiout = new RtMidiOut();
        m_midiin = new RtMidiIn();
        display_available_out_devices();
        m_midiout->openPort( 1 );
        m_midiin->openPort( 0 );

        // Set our callback function.  This should be done immediately after
        // opening the port to avoid having incoming messages written to the
        // queue.
        m_midiin->setCallback( &on_midi );
        // Don't ignore sysex, timing, or active sensing messages.
        m_midiin->ignoreTypes( false, false, false );
    }
    catch ( RtMidiError &error ) {
        error.printMessage();
        exit( EXIT_FAILURE );
    }

    for (int i = 0; i < 15; i++)
    {
        m_pressed.push_back(std::vector<unsigned int>{});
    }
    

}

Player* Player::get_instance() {
    if(!s_player) s_player = new Player();
    return s_player;
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

void Player::on_midi( double deltatime, std::vector< unsigned char > *message, void *userData )
{

    Player *player = get_instance();
    unsigned int nBytes = message->size();
    if((*message)[1] == (unsigned char)60 && (*message)[0] == (unsigned char)144) {
        // midi_clock = true;
        std::cout << "CLOCK" << std::endl;
        std::cout << "CLOCK" << std::endl;
        std::cout << "duration: " << s_current_phrase[s_current_time][2] << std::endl;
        s_note_time++;

        if(s_note_time > s_current_phrase[s_current_time][2] - 1) {
            s_current_time = (s_current_time + 1) % s_current_phrase.size();
            player->play_chord(s_current_phrase[s_current_time][0], 3, s_current_phrase[s_current_time][1], 0);
            player->play_chord(s_current_phrase[s_current_time][0], 2, 2, 1);
            s_note_time = 0;
        }
    }
  // for ( unsigned int i=0; i<nBytes; i++ )
  //   // std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  // if ( nBytes > 0 )
    // std::cout << "stamp = " << deltatime << std::endl;
}

void Player::play_chord(int note, int octave, int number, unsigned int channel) {
    m_message[2] = 90;
    
    if(channel > 15) {
        std::cout << "invalid channel" << std::endl;
        return;
    }

    std::cout << "channel: " << channel << std::endl;

    unsigned int first_byte = 128 + channel;
    std::cout << "fb : " << first_byte << std::endl;

    // Note Off
    m_message[0] = first_byte;
    while (m_pressed[channel].size() > 0)
    {   
        // std::cout << "note off : " << m_pressed[m_pressed.size() - 1][1] << std::endl;
        m_message[0] = 128 + channel;
        m_message[1] = m_pressed[channel][m_pressed[channel].size() - 1];
        m_pressed[channel].pop_back();
        m_midiout->sendMessage( &m_message );
    }

    first_byte = 144 + channel;
    std::cout << "fb : " << first_byte << std::endl;

    // Note On
    m_message[0] = first_byte;
    for (int i = 0; i < number - 1; i++)
    {
        unsigned int pressed_note = m_range.get_note(note + i * 2, octave);
        m_pressed[channel].push_back(pressed_note);
        m_message[1] = pressed_note;
        m_midiout->sendMessage( &m_message );
    }

}