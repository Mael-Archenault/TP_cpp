#ifndef PARTYSTATE_H
#define PARTYSTATE_H


#include "GameState.h"
#include <SFML/Graphics.hpp>

class PartyState: public GameState{
    private:
        sf::RectangleShape background;
    public:
        PartyState();
        ~PartyState(){};

        void handleInput() override;
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
};

#endif