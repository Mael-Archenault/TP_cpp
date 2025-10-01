#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "Engine/GameState.h"
#include <SFML/Graphics.hpp>

class GameOverState : public GameState
{
private:
    sf::Font font;
    sf::Text title;
    sf::Text subtitle;
    sf::RectangleShape background;

public:
    GameOverState();

    void handleInput() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
};

#endif