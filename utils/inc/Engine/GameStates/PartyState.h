#ifndef PARTYSTATE_H
#define PARTYSTATE_H

#include "Engine/GameState.h"
#include "Engine/Game.h"
#include <SFML/Graphics.hpp>
#include "Pokemon/PokemonAttack.h"

class PartyState : public GameState
{
private:
    PokemonAttack &team;

    int spriteSize;
    float scale;

    sf::Font font;
    std::vector<sf::Text> names;
    sf::RectangleShape background;

public:
    PartyState(Game *context, PokemonAttack &team);

    void handleInput() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
};

#endif