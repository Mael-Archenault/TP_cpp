#include "Engine/Game.h"
#include "Engine/GameStates/ExplorationState.h"
#include "Engine/GameStates/ArenaState.h"
#include "Engine/GameStates/FightState.h"
#include "Engine/GameStates/PartyState.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include "Pokemon/Player.h"
#include "Utils/RenderableObject.h"


ExplorationState::ExplorationState(Player* player): player(player) {
    
    player->setPosition(sf::Vector2f(400-(int)(player->getSpriteWidth()/2), 300-(int)(player->getSpriteHeight()/2)));
    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(150, 250, 100));
}


void ExplorationState::handleInput(){


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        this->context->setState(new PartyState(this->context, player->getAttackTeam()));
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
        this->context->setState(new FightState(context,player));
    }
    else if (player->getPosition().x >= 780 - (int)(player->getSpriteWidth()/2)){
        this->context->setState(new ArenaState(context, player));
    }

    // waiting 0.1 seconds
    sf::sleep(sf::milliseconds(10));
    
}

void ExplorationState::render(sf::RenderWindow& window){
    window.draw(background);
    player->render(window, player->getPosition());
}



