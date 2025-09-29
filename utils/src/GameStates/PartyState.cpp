#include "GameStates/PartyState.h"
#include "GameStates/ExplorationState.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include <iostream>
PartyState::PartyState(Game* context, PokemonAttack& team): team(team)
{   
    context = context;
    background.setSize(sf::Vector2f(context->getWindowWidth(), context->getWindowHeight()));
    background.setFillColor(sf::Color(150, 10, 10));

    spriteSize = context->getWindowWidth()/4;
    scale = spriteSize/96;

    for (int i=0; i<team.size(); i++){
        std::cout<<i<<std::endl;
        Pokemon* pokemon = &team.at(i);
        pokemon->scale(scale, scale);
        sf::Text name;

        // Title setup
        name.setFont(font);
        name.setString(pokemon->getName());

        name.setCharacterSize(20);
        name.setFillColor(sf::Color(255,255,255));
        names.push_back(name);
    }

    if (team.size()>0){
        spriteSize = team.at(0).getWidth();
    }
    else{
        spriteSize = 0;
    }

    std::cout<<spriteSize<<std::endl;


    // Load font
    if (!font.loadFromFile("../sources/arial.ttf")) {
        std::cerr << "Error loading font\n";
    }

}

void PartyState::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        std::cout << "Switching to Exploration State" << std::endl;
        this->context->setState(new ExplorationState(this->context->getPlayer()));
    }
}
void PartyState::update(float deltaTime) {
    // Update logic for game over state
}
void PartyState::render(sf::RenderWindow& window) {
    window.draw(background);
    int xOffset = (int)context->getWindowWidth()/4;
    int yOffset = (int)(context->getWindowHeight()-3*spriteSize)/2;

    for (int i=0; i<team.size(); i++) {
        team.at(i).render(window, sf::Vector2f(xOffset+ (i%2)*spriteSize, yOffset+(int)(i/2)*spriteSize));
        sf::Text name = names.at(i);
        name.setPosition(sf::Vector2f(xOffset + (i%2)*spriteSize + 10, yOffset +(int)(i/2)*spriteSize));
        window.draw(name);
    }

    for (int i=0; i<6; i++){
        sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
        rectangle.setPosition(sf::Vector2f(xOffset + (i%2)*spriteSize, yOffset +(int)(i/2)*spriteSize));
        rectangle.setFillColor(sf::Color::Transparent);
        rectangle.setOutlineColor(sf::Color::White);
        rectangle.setOutlineThickness(1.0f);
        window.draw(rectangle);
    }
        
 
}