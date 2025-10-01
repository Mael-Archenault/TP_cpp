#ifndef HOMESTATE_H
#define HOMESTATE_H

#include "Engine/GameState.h"
#include <SFML/Graphics.hpp>

class HomeState : public GameState
{
private:
    sf::Text title;
    sf::Text subtitle;
    sf::RectangleShape background;
    sf::Font font;

public:
    HomeState();

    void handleInput() override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
};

#endif