#include <iostream>
#include "Pokedex.h"
#include "Pokemon.h"


int main(){
    std::cout<<"----Testing the Pokedex instantiation----"<<std::endl;
    std::cout<<"Creating a first reference of Pokedex"<<std::endl;
    Pokedex* pokedex_ptr = Pokedex::getInstance("../sources/pokedex.csv");

    // Making sure the Pokedex instance is a singleton

    std::cout<<"Creating a second reference of Pokedex"<<std::endl;
    Pokedex* pokedex_ptr_bis = Pokedex::getInstance("../sources/pokedex.csv");

    bool references_equal = (pokedex_ptr==pokedex_ptr_bis);
    if (references_equal == 1){
        std::cout<<"- the 2 references are equal"<<std::endl;
    }

    else{
        std::cout<<"- the 2 references are not the same"<< std::endl;
    }
    std::cout<<std::endl;


    // Testing Pokemon Fetching

    int target_id = 50;
    std::cout<<"Getting pokemon of id : "<<target_id<<std::endl;
    Pokemon pokemon1 = pokedex_ptr->getCloneById(target_id);
    std::cout<<"- id of the fetched pokemon: "<<pokemon1.getId()<<std::endl<<std::endl;

    std::string target_name = "Bulbasaur";
    std::cout<<"Getting pokemon with name : "<<target_name<<std::endl;
    Pokemon pokemon2 = pokedex_ptr->getCloneByName(target_name);
    std::cout<<"- name of the fetched pokemon: "<<pokemon2.getName()<<std::endl<<std::endl;

    return 0;
}