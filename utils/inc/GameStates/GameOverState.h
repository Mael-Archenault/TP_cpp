#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>

class GameOverState: public GameState{
    public:
        GameOverState(){};
        ~GameOverState(){};

        void handleInput() override;
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
};

#endif