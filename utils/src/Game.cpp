#include "Game.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Trainer.h"
#include "Pokedex.h"


Game::Game(GameState* initialState){
    state = initialState;
    state->setReferenceToContext(this);

    windowWidth = 800;
    windowHeight = 600;
    window.create(sf::VideoMode(windowWidth, windowHeight), "Game Window");


    player = new Trainer(1, "Nate", "../sources/player_sprite.png", sf::Vector2f(400, 300));
    if (!player) {
        std::cerr << "Error creating player Trainer instance" << std::endl;
    } else {
        std::cout << "Player Trainer instance created successfully" << std::endl;
    }
    pokedex = Pokedex::getInstance("../sources/pokedex.csv");
    pokedex->displayById();
    

}


void Game::setState(GameState* state){
    this->state = state;
    this->state->setReferenceToContext(this);
}

Trainer* Game::getPlayer(){
    return this->player;
}


void Game::run(){
    float deltaTime = 0.0016f; // Assuming a fixed time step for simplicity
    while (true) {// Main game loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!window.isOpen())
            break;


        state->handleInput();
        state->update(deltaTime);
        
        window.clear();
        state->render(window);
        window.display();
    }
}


int Game::getWindowWidth(){
    return windowWidth;
}

int Game::getWindowHeight(){
    return windowHeight;
}

Pokedex* Game::getPokedex(){
    return pokedex;
}