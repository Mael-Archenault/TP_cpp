#include "Game.h"
#include "GameStates/ExplorationState.h"
#include "GameStates/ArenaState.h"
#include "GameStates/FightState.h"
#include "GameStates/PartyState.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "Trainer.h"
#include "RenderableObject.h"


ExplorationState::ExplorationState(Trainer* player): player(player) {
    
    player->setPosition(sf::Vector2f(400-(int)(player->getSpriteWidth()/2), 300-(int)(player->getSpriteHeight()/2)));
    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(150, 250, 100));
}


void ExplorationState::handleInput(){


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        std::cout << "Switching to Party State" << std::endl;
        this->context->setState(new PartyState());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        this->player->goUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->player->goDown();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        this->player->goLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->player->goRight();
    }
    else {
        this->player->setMoving(false);
    }
}

void ExplorationState::update(float deltaTime){
    player->update(deltaTime+0.01);

    if (player->getPosition().x <= 20-(int)(player->getSpriteWidth()/2)){
        std::cout << "Switching to Fight State" << std::endl;
        this->context->setState(new FightState());
    }
    else if (player->getPosition().x >= 780 - (int)(player->getSpriteWidth()/2)){
        std::cout << "Switching to Arena State" << std::endl;
        this->context->setState(new ArenaState());
    }

    // waiting 0.1 seconds
    sf::sleep(sf::milliseconds(10));
    
}

void ExplorationState::render(sf::RenderWindow& window){
    window.draw(background);
    player->render(window, player->getPosition());
}



