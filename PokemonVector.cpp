//
// Created by mael-archenault on 9/10/25.
//

#include "PokemonVector.h"
#include <algorithm>
#include <vector>



PokemonVector::PokemonVector()
{
    std::vector<Pokemon> pokemons;
}

PokemonVector::~PokemonVector()
{
}




Pokemon PokemonVector::getById(int id)
{
    for (Pokemon pokemon: this->pokemons)
    {
        if (pokemon.getId() == id)
        {
            return pokemon;
        }
    }
    return Pokemon(-1, "MissingNo", 0,0,0,0,0);
}

Pokemon PokemonVector::getByName(std::string name)
{
    for (Pokemon pokemon: this->pokemons)
    {
        if (pokemon.getName() == name)
        {
            return pokemon;
        }
    }
    return Pokemon(-1, "MissingNo", 0,0,0,0,0);
}


void PokemonVector::displayById()
{

    std::vector<Pokemon> sorted_pokemons(this->pokemons);
    std::sort(sorted_pokemons.begin(), sorted_pokemons.end(),compareId);
    for (Pokemon pokemon: sorted_pokemons)
    {
        pokemon.display();
    }
}

void PokemonVector::displayByName()
{

    std::vector<Pokemon> sorted_pokemons(this->pokemons);
    std::sort(sorted_pokemons.begin(), sorted_pokemons.end(),compareName);

    for (Pokemon pokemon: sorted_pokemons)
    {
        pokemon.display();
    }
}



bool PokemonVector::compareName(Pokemon& pokemon1, Pokemon& pokemon2)
{
    return pokemon1.getName() < pokemon2.getName();
}

bool PokemonVector::compareId(Pokemon& pokemon1, Pokemon& pokemon2)
{
    return pokemon1.getId() < pokemon2.getId();
}