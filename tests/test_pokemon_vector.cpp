#include <iostream>
#include "Pokemon.h"
#include "PokemonVector.h"


int main(){
    std::cout<<"----Testing the PokemonVector instantiation----"<<std::endl;
    std::cout<<"Creating an instance of PokemonVector"<<std::endl<<std::endl;

    PokemonVector pokemonVector;



    Pokemon pokemon1(1,"Bulbasaur", 0,100,50,40,20);
    Pokemon pokemon2(2,"Pikachu", 0,100,50,40,20);

    // Testing the PokemonVector Class Methods

    std::cout<<"Adding a first pokemon to the vector : "<<pokemon1.getName()<<std::endl;
    pokemonVector.addPokemon(pokemon1);

    std::cout<<"Adding a second pokemon to the vector : "<<pokemon2.getName()<<std::endl;
    pokemonVector.addPokemon(pokemon2);


    std::cout<<"Pokemon list current state:"<<std::endl;
    pokemonVector.displayById();

    std::cout<<"Removing the first pokemon from the vector"<<std::endl;
    pokemonVector.removePokemon(0);

    std::cout<<"Pokemon list current state:"<<std::endl;
    pokemonVector.displayByName();
    
    return 0;
}