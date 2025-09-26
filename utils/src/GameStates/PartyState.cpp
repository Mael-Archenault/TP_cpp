#include "GameStates/PartyState.h"
#include "GameStates/ExplorationState.h"
#include <SFML/Window/Keyboard.hpp>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include <iostream>
PartyState::PartyState(){
    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(150, 250, 100));
}

void PartyState::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        std::cout << "Switching to Home State" << std::endl;
        this->context->setState(new ExplorationState(this->context->getPlayer()));
    }
}
void PartyState::update(float deltaTime) {
    // Update logic for game over state
}
void PartyState::render(sf::RenderWindow& window) {
    window.draw(background);



    //std::cout << "Rendering Party State" << std::endl;
    Pokemon& pokemon = context->getPlayer()->getAttackTeam().getPokemon(0);
    std::cout<<&pokemon<<std::endl;

    // sf::Vector2u size = pokemon.texture->getSize();
    // if (size.x == 0 || size.y == 0) {
    //     std::cerr << "Texture has invalid size!" << std::endl;
    // } else {
    //     std::cout << "Texture size: " << size.x << "x" << size.y << std::endl;
    // }
    pokemon.render(window, sf::Vector2f(0.0f,0.0f));
    //pokemon.display();

}