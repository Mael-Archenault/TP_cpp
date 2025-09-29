#ifndef FIGHTSTATE_H
#define FIGHTSTATE_H

#include "GameState.h"
#include "Trainer.h"
#include "Pokemon.h"
#include "Game.h"
#include <SFML/Graphics.hpp>


class FightState : public GameState
{
private:
    Trainer* player;
    Pokemon* opponent;
    Pokemon* currentPokemon;

    sf::CircleShape opponentBase;
    sf::CircleShape base;

    sf::Texture* backgroundTexture;
    sf::Sprite backgroundSprite;
public:
    FightState(Game* context,Trainer* player);
    ~FightState(){};

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void handleInput() override;
};

#endif