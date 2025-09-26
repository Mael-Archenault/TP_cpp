#include "GameStates/FightState.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include "GameStates/ExplorationState.h"
#include "Game.h"
#include <iostream>


void FightState::update(float deltaTime)
{
    // Update fight logic here
}

void FightState::render(sf::RenderWindow& window)
{
    // Render fight state here
}

void FightState::handleInput()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        std::cout << "Switching to ExplorationState" << std::endl;
        context->setState(new ExplorationState(this->context->getPlayer()));
    }
    // Handle fight input here
}