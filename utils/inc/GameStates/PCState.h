#ifndef PCSTATE_H
#define PCSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class PCState: public GameState{
    public:
        PCState(){};
        ~PCState(){};

        void handleInput() override;
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
};

#endif