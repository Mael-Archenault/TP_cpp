#ifndef TP_CPP_POKEMONATTACK_H
#define TP_CPP_POKEMONATTACK_H

#include "PokemonParty.h"

class PokemonAttack : public PokemonVector
{

private:


public:
    PokemonAttack();
    void addPokemon(Pokemon pokemon);
    void display();
};


#endif //TP_CPP_POKEMONATTACK_H