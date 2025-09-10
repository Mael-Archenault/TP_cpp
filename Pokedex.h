#include "PokemonVector.h"

#ifndef TP_CPP_POKEDEX_H
#define TP_CPP_POKEDEX_H


class Pokedex: public PokemonVector
{
private:
    static Pokedex* instance;
    Pokedex(const std::string& nomFichier);

public:
    static Pokedex* getInstance(const std::string& nomFichier);
    ~Pokedex();

};


#endif //TP_CPP_POKEDEX_H