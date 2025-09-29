#include "Trainer.h"
#include "Pokemon.h"
#include "PokemonAttack.h"
#include "TextureManager.h"
#include <iostream>


Trainer::Trainer(int id, const std::string& name, const std::string& textureFile, sf::Vector2f position)
    : id(id), name(name), position(position)
{
    texture = TextureManager::getInstance().loadTexture(textureFile);
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setScale((float)scale, (float)scale); // Make the sprite twice as large
    speed = 5;



    // Initializing the team with 1 pokemon
    Pokemon first_pokemon = Pokemon(1, "Bulbasaur", 0, 100,100,100,100);
    Pokemon second_pokemon = Pokemon(4, "Charmander", 0, 100,100,100,100);
    Pokemon third_pokemon = Pokemon(7, "Squirtle", 0, 100,100,100,100);
    Pokemon fourth_pokemon = Pokemon(10, "Pidgey", 0, 100,100,100,100);
    Pokemon fifth_pokemon = Pokemon(25, "Pikachu", 0, 100,100,100,100);
    Pokemon sixth_pokemon = Pokemon(39, "Jigglypuff", 0, 100,100,100,100);
    attackTeam.addPokemon(third_pokemon);
    attackTeam.addPokemon(second_pokemon);
    attackTeam.addPokemon(first_pokemon);
    // attackTeam.addPokemon(fourth_pokemon);
    // attackTeam.addPokemon(fifth_pokemon);
    // attackTeam.addPokemon(sixth_pokemon);

}

int Trainer::getId() const {
    return id;
}

std::string Trainer::getName() const {
    return name;
}

PokemonAttack& Trainer::getAttackTeam(){
    return attackTeam;
}


void Trainer::update(float deltaTime) {
    if (moving==false){
        currentFrame=0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction*spriteHeight, spriteWidth, spriteHeight));
    }
    else if (this->lastFrameChangeTime >=0.2f) {
        currentFrame = (currentFrame + 1) % 3; // Assuming 4 frames in the sprite sheet
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction*spriteHeight, spriteWidth, spriteHeight));
        lastFrameChangeTime = 0.0f;
    }
    else {
        lastFrameChangeTime += deltaTime;
    }
}


void Trainer::goDown() {
    if (this->moving == false){
        this->moving = true;
    }
    this->position = this->position + sf::Vector2f(0, this->speed);
    if (direction!=1){
        direction=1;
        currentFrame=0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction*spriteHeight, spriteWidth, spriteHeight));
    }
}

void Trainer::goUp() {
    if (this->moving == false){
        this->moving = true;
    }
    this->position = this->position + sf::Vector2f(0, -this->speed);
    if (direction!=0){
        direction=0;
        currentFrame=0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction*spriteHeight, spriteWidth, spriteHeight));
    }
}

void Trainer::goLeft() {
    if (this->moving == false){
        this->moving = true;
    }
    this->position = this->position + sf::Vector2f(-this->speed, 0);
    if (direction!=2){
        direction=2;
        currentFrame=0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction*spriteHeight, spriteWidth, spriteHeight));
    }
}

void Trainer::goRight() {
    if (this->moving == false){
        this->moving = true;
    }
    this->position = this->position + sf::Vector2f(this->speed, 0);
    if (direction!=3){
        direction=3;
        currentFrame=0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction*spriteHeight, spriteWidth, spriteHeight));
    }
}

sf::Vector2f Trainer::getPosition(){
    return this->position;
}

void Trainer::setMoving(bool new_state){
    moving = new_state;
}

void Trainer::setPosition(sf::Vector2f new_position){
    this->position = new_position;
}