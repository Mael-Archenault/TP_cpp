#ifndef ARENASTATE_H
#define ARENASTATE_H

#include "Engine/GameState.h"
#include "Pokemon/Trainer.h"
#include "Engine/Game.h"
#include <SFML/Graphics.hpp>

class ArenaState : public GameState
{

private:
    Player *player;
    Trainer *champion;
    Pokemon *playerPokemon;
    Pokemon *championPokemon;

    sf::CircleShape base;
    sf::CircleShape opponentBase;

    sf::Texture *backgroundTexture;
    sf::Sprite backgroundSprite;

public:
    ArenaState(Game *context, Player *player);

    void handleInput() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
};

#endif