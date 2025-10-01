#include <iostream>
#include "Pokemon/Pokemon.h"
#include "Pokemon/PokemonParty.h"


int main(){
    std::cout<<"----Testing the PokemonParty instantiation----"<<std::endl;
    std::cout<<"Creating an instance of PokemonParty"<<std::endl<<std::endl;

    PokemonParty pokemonParty;



    Pokemon pokemon1(1,"Bulbasaur", 0,100,50,40,20);
    Pokemon pokemon2(2,"Pikachu", 0,100,50,40,20);

    // Testing the PokemonVector Class Methods

    std::cout<<"Adding a first pokemon to the party : "<<pokemon1.getName()<<std::endl;
    pokemonParty.addPokemon(pokemon1);

    std::cout<<"Adding a second pokemon to the party : "<<pokemon2.getName()<<std::endl;
    pokemonParty.addPokemon(pokemon2);


    std::cout<<"Pokemon list current state:"<<std::endl;
    pokemonParty.display();

    std::cout<<"Removing the first pokemon from the vector"<<std::endl;
    pokemonParty.removePokemon(0);

    std::cout<<"Pokemon list current state:"<<std::endl;
    pokemonParty.display();
    
    return 0;
}