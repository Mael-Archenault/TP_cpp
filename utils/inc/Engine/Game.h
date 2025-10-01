#ifndef GAME_H
#define GAME_H

#include "Engine/GameState.h"
#include "Pokemon/Player.h"
#include "Pokemon/Pokedex.h"

#include <SFML/Graphics.hpp>

class Game
{
private:
    GameState *state;

    Player *player;
    Pokedex *pokedex;

    sf::RenderWindow window;

    int windowWidth;
    int windowHeight;

public:
    Game(GameState *initialState);

    void setState(GameState *state);

    Player *getPlayer();
    Pokedex *getPokedex();
    int getWindowWidth();
    int getWindowHeight();

    void run();
};

#endif