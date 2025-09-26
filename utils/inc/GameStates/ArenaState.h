#ifndef ARENASTATE_H
#define ARENASTATE_H


#include "GameState.h"
#include <SFML/Graphics.hpp>

class ArenaState: public GameState{
    public:
        ArenaState(){};
        ~ArenaState(){};

        void handleInput() override;
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
};

#endif