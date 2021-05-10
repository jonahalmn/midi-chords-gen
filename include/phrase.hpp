#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>
#include <ctime>

class Phrase {
    protected:
        std::vector<std::vector<unsigned int>> m_params;
        nlohmann::json m_tree;

    public:
        Phrase();

        void populate();
        std::vector<std::vector<unsigned int>> generate_phrase();
};