#include "Engine/GameStates/HomeState.h"
#include "Engine/GameStates/ExplorationState.h"
#include "Engine/Game.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

HomeState::HomeState() {
    // Load font
    if (!font.loadFromFile("../sources/Pokemon Solid.ttf")) {
        std::cerr << "Error loading font\n";
    }


    // Title setup
    title.setFont(font);
    title.setString("Pokemon");

    title.setCharacterSize(100);
    title.setFillColor(sf::Color(47, 61, 76));
    title.setStyle(sf::Text::Bold);


    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);

    title.setPosition(800/ 2.0f, 600 / 2.0f);
    

    // Subtitle setup

    subtitle.setFont(font);
    subtitle.setString("Press E to start");

    subtitle.setCharacterSize(30);
    subtitle.setFillColor(sf::Color(47, 61, 76));
    subtitle.setStyle(sf::Text::Bold);
    sf::FloatRect subtitleRect = subtitle.getLocalBounds();
    subtitle.setOrigin(subtitleRect.left + subtitleRect.width / 2.0f,
                          subtitleRect.top + subtitleRect.height / 2.0f);

    subtitle.setPosition(800 / 2.0f, 600 / 2.0f + 100);

    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(100, 100, 250));
}

void HomeState::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        this->context->setState(new ExplorationState(this->context->getPlayer()));
    }
}

void HomeState::update(float deltaTime) {
    // Update logic for home state
}

void HomeState::render(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(title);
    window.draw(subtitle);
}
