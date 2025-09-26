#ifndef EXPLORATIONSTATE_H
#define EXPLORATIONSTATE_H


#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "Trainer.h"


class ExplorationState: public GameState{
    private:
        Trainer* player;

        sf::RectangleShape background;
    public:
        ExplorationState(Trainer* player);
        void handleInput() override;
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
};

#endif