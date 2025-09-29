//
// Created by mael-archenault on 9/12/25.
//

#include "PokemonAttack.h"
#include "PokemonParty.h"


PokemonAttack::PokemonAttack()
{

}



void PokemonAttack::addPokemon(Pokemon& pokemon)
{
    if (pokemons.size() == 6)
    {
        std::cout << "Already 6 pokemons in the team, pokemon not added" << std::endl;
        return;
    }
    pokemons.push_back(pokemon);
}



void PokemonAttack::display()
{
    for (int i = 0; i < pokemons.size(); i++)
    {

        std::cout<<i+1<<" ";
        pokemons.at(i).display();
    }
}