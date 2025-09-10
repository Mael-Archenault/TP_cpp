//
// Created by mael-archenault on 9/10/25.
//

#ifndef TP_CPP_POKEMONPARTY_H
#define TP_CPP_POKEMONPARTY_H

#include "PokemonVector.h"


class PokemonParty: public PokemonVector
{
private:
public:
    PokemonParty();
    void addPokemonToParty(Pokemon pokemon);
    void removePokemonFromParty(Pokemon pokemon);
};


#endif //TP_CPP_POKEMONPARTY_H