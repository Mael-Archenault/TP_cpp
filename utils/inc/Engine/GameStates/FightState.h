#ifndef FIGHTSTATE_H
#define FIGHTSTATE_H

#include "Engine/Game.h"
#include "Engine/GameState.h"
#include "Pokemon/Trainer.h"
#include "Pokemon/Pokemon.h"
#include <SFML/Graphics.hpp>

class FightState : public GameState
{
private:
    Trainer *player;
    Pokemon *opponent;
    Pokemon *currentPokemon;

    sf::CircleShape opponentBase;
    sf::CircleShape base;

    sf::Texture *backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    FightState(Game *context, Trainer *player);

    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
    void handleInput() override;
};

#endif