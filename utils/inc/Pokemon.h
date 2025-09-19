#pragma once

#include <iostream>

#include "RenderableObject.h"

class Pokemon: public RenderableObject {
private:

    int id{};
    std::string name;
    int evolution{};
    double maxHP{};
    double HP{};
    double attack{};
    double defense{};
    double heal(double amount);

public:

    Pokemon(int id,
            std::string name,
            int evolution,
            double maxHP,
            double HP,
            double attack,
            double defense);

    Pokemon(const Pokemon &base);

    std::string getName();
    int getId();

    void display();
};





