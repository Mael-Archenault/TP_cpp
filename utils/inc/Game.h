#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Trainer.h"
#include "Pokedex.h"

#include <SFML/Graphics.hpp>



class Game
{
private:
    GameState* state;

    Trainer* player;

    Pokedex* pokedex;

    sf::RenderWindow window;

    int windowWidth;
    int windowHeight;

public:
    Game(GameState* initialState);

    void setState(GameState* state);
    Trainer* getPlayer();
    Pokedex* getPokedex();
    
    int getWindowWidth();
    int getWindowHeight();
    void run();
};
       

#endif