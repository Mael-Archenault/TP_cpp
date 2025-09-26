#include "GameStates/GameOverState.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include "GameStates/HomeState.h"
#include "Game.h"
#include <iostream>

void GameOverState::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        std::cout << "Switching to Home State" << std::endl;
        this->context->setState(new HomeState());
    }
}
void GameOverState::update(float deltaTime) {
    // Update logic for game over state
}
void GameOverState::render(sf::RenderWindow& window) {
    // Render logic for game over state
}