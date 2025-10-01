
#ifndef TP_CPP_POKEMONPARTY_H
#define TP_CPP_POKEMONPARTY_H

#include "Pokemon/PokemonVector.h"

class PokemonParty : public PokemonVector
{
public:
    PokemonParty() {};
    void display();
};

#endif // TP_CPP_POKEMONPARTY_H