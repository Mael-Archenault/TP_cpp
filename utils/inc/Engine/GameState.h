#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

class Game;

class GameState
{
protected:
    Game *context;

public:
    GameState() {};

    virtual void handleInput() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow &window) = 0;

    void setReferenceToContext(Game *context)
    {
        this->context = context;
    }
};

#endif