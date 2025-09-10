#pragma once

#include <iostream>

class Pokemon {
private:

    int id{};
    std::string name;
    int evolution{};
    double maxHP{};
    double HP{};
    double attack{};
    double defense{};

public:

    Pokemon(int id,
            std::string name,
            int evolution,
            double maxHP,
            double HP,
            double attack,
            double defense);

    Pokemon(const Pokemon &base);

    ~Pokemon();

    std::string getName();
    int getId();

    void display();
};





