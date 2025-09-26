#include <iostream>
#include "Pokemon.h"


int main(){
    std::cout<<"----Testing the Pokemon instantiation----"<<std::endl;
    std::cout<<"Creating an instance of Pokemon"<<std::endl<<std::endl;
    Pokemon pokemon(1,"Bulbasaur", 0,100,50,40,20);

    // Testing the Pokemon Class Methods

    std::cout<<"Name of the pokemon: "<<pokemon.getName()<<std::endl;

    std::cout<<"Id of the pokemon: "<<pokemon.getId()<<std::endl<<std::endl;

    std::cout<<"Displaying Instance attributes"<<std::endl<<"- ";
    pokemon.display();
    std::cout<<std::endl;


    // Testing copy Constructor

    std::cout<<"Testing copy constructor"<<std::endl;
    Pokemon pokemon2(pokemon);
    
    std::cout<<"Displaying Instance attributes"<<std::endl<<"- ";
    pokemon2.display();
    std::cout<<std::endl;


    
    return 0;
}