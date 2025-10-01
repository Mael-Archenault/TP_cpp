#include "Pokemon/Trainer.h"
#include "Pokemon/Pokemon.h"
#include "Pokemon/PokemonAttack.h"
#include "Pokemon/Pokedex.h"
#include "Utils/TextureManager.h"
#include <iostream>

Trainer::Trainer(int id, const std::string &name, const std::string &textureFile, sf::Vector2f position)
    : id(id), name(name), position(position)
{
    this->setSprite(textureFile);

    Pokemon randomPokemon = Pokedex::getInstance("../sources/pokedex.csv")->getRandomPokemon();
    attackTeam.addPokemon(randomPokemon);

    spriteWidth = 32;
    spriteHeight = 33;
    scaleFactor = 4;
}

int Trainer::getId() const
{
    return id;
}

std::string Trainer::getName() const
{
    return name;
}

PokemonAttack &Trainer::getAttackTeam()
{
    return attackTeam;
}

sf::Vector2f Trainer::getPosition()
{
    return this->position;
}

void Trainer::setPosition(sf::Vector2f new_position)
{
    this->position = new_position;
}

int Trainer::getSpriteWidth()
{
    return this->spriteWidth * scaleFactor;
}

int Trainer::getSpriteHeight()
{
    return this->spriteHeight * scaleFactor;
}
