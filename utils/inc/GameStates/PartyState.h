#ifndef PARTYSTATE_H
#define PARTYSTATE_H


#include "GameState.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include "PokemonAttack.h"

class PartyState: public GameState{
    private:
        sf::RectangleShape background;

        PokemonAttack& team;

        int spriteSize;
        float scale;

        sf::Font font;
        std::vector<sf::Text> names;

    public:
        PartyState(Game* context, PokemonAttack& team);
        ~PartyState(){};

        void handleInput() override;
        void update(float deltaTime) override;
        void render(sf::RenderWindow& window) override;
};

#endif