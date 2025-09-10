//
// Created by mael-archenault on 9/10/25.
//

#include "PokemonParty.h"

PokemonParty::PokemonParty()
{

}


void PokemonParty::addPokemonToParty(Pokemon pokemon)
{
    pokemons.push_back(pokemon);
}
void PokemonParty::removePokemonFromParty(Pokemon pokemon)
{
    int index = 0;
    for (Pokemon pokemonInParty : pokemons)
    {
        if (pokemonInParty.getName() == pokemon.getName())
        {
            pokemons.erase(pokemons.begin() + index);
        }
        index++;
    }
}