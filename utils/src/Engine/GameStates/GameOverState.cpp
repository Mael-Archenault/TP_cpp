#include "Engine/GameStates/GameOverState.h"
#include "Engine/GameStates/HomeState.h"
#include "Engine/Game.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include <iostream>


GameOverState::GameOverState(){
    // Load font
    if (!font.loadFromFile("../sources/Pokemon Solid.ttf")) {
        std::cerr << "Error loading font\n";
    }


    // Title setup
    title.setFont(font);
    title.setString("Game Over");

    title.setCharacterSize(100);
    title.setFillColor(sf::Color(47, 0,0));
    title.setStyle(sf::Text::Bold);


    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);

    title.setPosition(800/ 2.0f, 600 / 2.0f);
    

    // Subtitle setup

    subtitle.setFont(font);
    subtitle.setString("Press H to restart");

    subtitle.setCharacterSize(30);
    subtitle.setFillColor(sf::Color(47, 0, 0));
    subtitle.setStyle(sf::Text::Bold);
    sf::FloatRect subtitleRect = subtitle.getLocalBounds();
    subtitle.setOrigin(subtitleRect.left + subtitleRect.width / 2.0f,
                          subtitleRect.top + subtitleRect.height / 2.0f);

    subtitle.setPosition(800 / 2.0f, 600 / 2.0f + 100);

    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(100, 100, 250));
}

void GameOverState::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        this->context->setState(new HomeState());
    }
}
void GameOverState::update(float deltaTime) {
    // Update logic for game over state
}
void GameOverState::render(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(title);
    window.draw(subtitle);
}