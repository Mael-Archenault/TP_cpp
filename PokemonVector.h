#include "Pokemon.h"
#include <vector>

#ifndef TP_CPP_POKEMONVECTOR_H
#define TP_CPP_POKEMONVECTOR_H


class PokemonVector
{
private:


public:


    std::vector<Pokemon> pokemons;

    PokemonVector();

    Pokemon getById(int id);
    Pokemon getByName(std::string name);


    void displayById();
    void displayByName();

    static bool compareId(Pokemon& pokemon1, Pokemon& pokemon2);
    static bool compareName(Pokemon& pokemon1, Pokemon& pokemon2);

};



#endif //TP_CPP_POKEMONVECTOR_H