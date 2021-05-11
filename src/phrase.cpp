#include "../include/phrase.hpp"

Phrase::Phrase() {
    // read a JSON file
    std::ifstream file("data/data.json");
    file >> m_tree;

    populate();
}

std::vector<std::vector<unsigned int>> Phrase::generate_phrase() {
    std::vector<std::vector<unsigned int>> notes;
    unsigned int current_state = 0;

    srand((int)time(NULL));

    for (int i = 0; i < 7; i++)
    {
        notes.push_back(std::vector<unsigned int>{m_params[current_state]});
        unsigned int probability = (rand() % 1000 * (unsigned int)m_tree[current_state][m_tree[current_state].size() - 1]) / 1000;
        std::cout << probability << std::endl;
        std::cout << m_tree[current_state][m_tree[current_state].size() - 1] << std::endl;
        unsigned int accumulator = 0;
        unsigned int j = 0;

        std::cout << "probability : " << probability << std::endl;


        while (accumulator < probability)
        {
            accumulator += (unsigned int)m_tree[current_state][j];
            j++;
        }
        
        current_state = j;

    }
    

    // notes.push_back(0);
    // notes.push_back(-1);
    // notes.push_back(0);
    // notes.push_back(-1);

    // notes.push_back(5);
    // notes.push_back(3);
    // notes.push_back(0);
    // notes.push_back(3);

    return notes;
}

void Phrase::populate() {
    for (unsigned int i = 1; i <= 3; i++)
    {  
        for (unsigned int j = 0; j < 7; j++)
        {
            m_params.push_back(std::vector< unsigned int>{j, i + 3});
            std::cout << "[ " << j << ";" << i + 2 << " ]" << std::endl;
        }
    }

    std::vector<int> state_prob = m_tree.at(0);
}