#ifndef EXPLORATIONSTATE_H
#define EXPLORATIONSTATE_H

#include "Engine/GameState.h"
#include "Pokemon/Player.h"
#include <SFML/Graphics.hpp>

class ExplorationState : public GameState
{
private:
    Player *player;
    sf::RectangleShape background;

public:
    ExplorationState(Player *player);
    void handleInput() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
};

#endif