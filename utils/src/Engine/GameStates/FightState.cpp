#include "Engine/GameStates/FightState.h"
#include "Engine/GameStates/ExplorationState.h"
#include "Engine/Game.h"
#include "Pokemon/Pokemon.h"
#include "Pokemon/Pokedex.h"
#include "Utils/TextureManager.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include <iostream>


FightState::FightState(Game* context,Trainer* player)
    : player(player)
    {

    opponent = new Pokemon(context->getPokedex()->getRandomPokemon());
    context = context;

    currentPokemon = &player->getAttackTeam().at(0);
    float scale = 4.0f;
    opponent->scale(scale, scale);
    currentPokemon->scale(scale, scale);


    float baseRadius = 50.f;                
    float rx = 120.f;                     
    float ry = 60.f;    

    base.setRadius(baseRadius);
    opponentBase.setRadius(baseRadius);

    base.setFillColor(sf::Color::Green);
    base.setOutlineThickness(3.f);
    base.setOutlineColor(sf::Color::Blue);
    base.setOrigin(baseRadius, baseRadius);
    base.setScale(rx / baseRadius, ry / baseRadius);

    opponentBase.setFillColor(sf::Color::Red);
    opponentBase.setOutlineThickness(3.f);
    opponentBase.setOutlineColor(sf::Color::Yellow);
    opponentBase.setOrigin(baseRadius, baseRadius);
    opponentBase.setScale(rx / baseRadius, ry / baseRadius);

    opponentBase.setPosition(sf::Vector2f(context->getWindowWidth()/2 + 96*scale/2,96*scale*3/5));
    base.setPosition(sf::Vector2f(96*scale/2, context->getWindowHeight()*3/4));


    std::string image_path = "../sources/battle_backgrounds.png";
    backgroundTexture = TextureManager::getInstance().loadTexture(image_path);
    if (backgroundTexture) {
        backgroundSprite.setTexture(*backgroundTexture);
    }

    // get a random integer between 1 and 12
    int random = rand() % 12 +1;

    backgroundSprite.setTextureRect(sf::IntRect(random%3 *256,(int)(random/3)+16,256,145));
    backgroundSprite.setScale((float)context->getWindowWidth()/256, (float)context->getWindowHeight()/145);

}

void FightState::update(float deltaTime)
{
    // Update fight logic here
}

void FightState::render(sf::RenderWindow& window)
{

    window.draw(backgroundSprite);
    window.draw(base);
    window.draw(opponentBase);
    currentPokemon->render(window, sf::Vector2f(0, context->getWindowHeight()/3));
    opponent->render(window, sf::Vector2f(context->getWindowWidth()/2, 0));

}

void FightState::handleInput()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
        std::cout << "Captured the pokemon" << std::endl;
        player->getAttackTeam().addPokemon(*opponent);
        context->setState(new ExplorationState(this->context->getPlayer()));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        std::cout << "Ran away from the fight" << std::endl;
        context->setState(new ExplorationState(this->context->getPlayer()));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
        std::cout << "Knocked out the opponent" << std::endl;
        context->setState(new ExplorationState(this->context->getPlayer()));
    }
}