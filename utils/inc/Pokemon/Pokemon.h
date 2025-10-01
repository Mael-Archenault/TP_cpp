#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include "Utils/RenderableObject.h"

class Pokemon : public RenderableObject
{
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

    std::string getName();
    int getId();

    void display();
};

#endif
