#ifndef TP_CPP_POKEDEX_H
#define TP_CPP_POKEDEX_H

#include "Pokemon/PokemonVector.h"

class Pokedex : public PokemonVector
{
private:
    static Pokedex *instance;
    Pokedex(const std::string &nomFichier);

public:
    static Pokedex *getInstance(const std::string &nomFichier);

    Pokemon getCloneById(int id);
    Pokemon getCloneByName(const std::string name);
    Pokemon getRandomPokemon();
};

#endif // TP_CPP_POKEDEX_H