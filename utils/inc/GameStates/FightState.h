#ifndef FIGHTSTATE_H
#define FIGHTSTATE_H

#include "GameState.h"
#include <SFML/Graphics.hpp>


class FightState : public GameState
{
public:
    FightState(){};
    ~FightState(){};

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void handleInput() override;
};

#endif