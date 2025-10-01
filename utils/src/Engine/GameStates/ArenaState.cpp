#include "Engine/GameStates/ArenaState.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include "Engine/GameStates/ExplorationState.h"
#include "Engine/GameStates/GameOverState.h"
#include "Engine/Game.h"
#include <iostream>
#include "Pokemon/Player.h"
#include "Utils/TextureManager.h"

ArenaState::ArenaState(Game* context, Player* player): player(player){
    context = context;


    std::string path = "../sources/champions_sprites/" + std::to_string(rand()%2+1) + ".png";
    champion = new Trainer(2, "Champion", path, sf::Vector2f(400, 300));
    champion->getHeight();
    champion->scale(2.0f, 2.0f);

    // get a random integer between 0 and the size of pokedex
   
    championPokemon = new Pokemon(champion->getAttackTeam().at(0));
    context = context;

    playerPokemon = &player->getAttackTeam().at(0);
    float scale = 4.0f;
    playerPokemon->scale(scale, scale);
    championPokemon->scale(scale, scale);


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

void ArenaState::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        std::cout << "Knocked out opponent" << std::endl;
        this->context->setState(new ExplorationState(this->context->getPlayer()));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        this->context->setState(new GameOverState());
    }
}

void ArenaState::update(float deltaTime) {
    // Update logic for arena state
}

void ArenaState::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);

    window.draw(base);
    window.draw(opponentBase);

    playerPokemon->render(window, sf::Vector2f(0, context->getWindowHeight()/3));
    champion->render(window, sf::Vector2f(context->getWindowWidth()/2, 0));
    championPokemon->render(window, sf::Vector2f(context->getWindowWidth()/2, 0));

    // Render logic for arena state
}
