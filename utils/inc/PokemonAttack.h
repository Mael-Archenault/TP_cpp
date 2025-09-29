    #ifndef TP_CPP_POKEMONATTACK_H
    #define TP_CPP_POKEMONATTACK_H

    #include "PokemonParty.h"
    #include "Pokemon.h"

    class PokemonAttack : public PokemonVector
    {


    public:
        PokemonAttack();
        void addPokemon(Pokemon& pokemon);
        void display();
    };


    #endif //TP_CPP_POKEMONATTACK_H