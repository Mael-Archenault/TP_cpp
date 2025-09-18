#include <iostream>
#include "Pokemon.h"
#include "PokemonAttack.h"


int main(){
    std::cout<<"----Testing the PokemonAttack class----"<<std::endl;
    std::cout<<"Creating an instance of PokemonAttack"<<std::endl<<std::endl;

    PokemonAttack pokemonAttack;



    Pokemon pokemon1(1,"Bulbasaur", 0,100,50,40,20);
    Pokemon pokemon2(2,"Pikachu", 0,100,50,40,20);
    Pokemon pokemon3(3,"Charmander", 0,100,50,40,20);
    Pokemon pokemon4(4,"Squirtle", 0,100,50,40,20);
    Pokemon pokemon5(5,"Caterpie", 0,100,50,40,20);
    Pokemon pokemon6(6,"Weedle", 0,100,50,40,20);
    Pokemon pokemon7(7,"Pidgey", 0,100,50,40,20);


    // Testing the PokemonVector Class Methods

    std::cout<<"Adding a first pokemon to the party : "<<pokemon1.getName()<<std::endl;
    pokemonAttack.addPokemon(pokemon1);

    std::cout<<"Adding a second pokemon to the party : "<<pokemon2.getName()<<std::endl;
    pokemonAttack.addPokemon(pokemon2);

    std::cout<<"Adding a third pokemon to the party : "<<pokemon3.getName()<<std::endl;
    pokemonAttack.addPokemon(pokemon3);

    std::cout<<"Adding a fourth pokemon to the party : "<<pokemon4.getName()<<std::endl;
    pokemonAttack.addPokemon(pokemon4);

    std::cout<<"Adding a fifth pokemon to the party : "<<pokemon5.getName()<<std::endl;
    pokemonAttack.addPokemon(pokemon5);

    std::cout<<"Adding a sixth pokemon to the party : "<<pokemon6.getName()<<std::endl;
    pokemonAttack.addPokemon(pokemon6);

    std::cout<<"Adding a seventh pokemon to the party : "<<pokemon7.getName()<<std::endl;
    pokemonAttack.addPokemon(pokemon7);



    std::cout<<"Pokemon list current state:"<<std::endl;
    pokemonAttack.display();

    std::cout<<"Removing the first pokemon from the vector"<<std::endl;
    pokemonAttack.removePokemon(0);

    std::cout<<"Pokemon list current state:"<<std::endl;
    pokemonAttack.display();
    
    return 0;
}