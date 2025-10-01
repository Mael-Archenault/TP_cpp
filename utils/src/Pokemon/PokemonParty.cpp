#include "Pokemon/PokemonParty.h"

void PokemonParty::display()
{
    for (int i = 0; i < pokemons.size(); i++)
    {
        std::cout << i + 1 << " ";
        pokemons.at(i).display();
    }
}