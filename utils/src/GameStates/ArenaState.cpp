#include "GameStates/ArenaState.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include "GameStates/ExplorationState.h"
#include "GameStates/GameOverState.h"
#include "Game.h"
#include <iostream>


void ArenaState::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        std::cout << "Switching to Exploration State" << std::endl;
        this->context->setState(new ExplorationState(this->context->getPlayer()));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        std::cout << "Switching to Game Over State" << std::endl;
        this->context->setState(new GameOverState());
    }
}

void ArenaState::update(float deltaTime) {
    // Update logic for arena state
}

void ArenaState::render(sf::RenderWindow& window) {
    // Render logic for arena state
}
