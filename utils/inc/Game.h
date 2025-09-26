#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Trainer.h"

#include <SFML/Graphics.hpp>



class Game
{
private:
    GameState* state;

    Trainer* player;

    sf::RenderWindow window;

public:
    Game(GameState* initialState);

    void setState(GameState* state);
    Trainer* getPlayer();
    void run();
};
       

#endif