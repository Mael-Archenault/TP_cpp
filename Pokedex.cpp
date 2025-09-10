//
// Created by mael-archenault on 9/10/25.
//

#include "Pokedex.h"
#include "Pokemon.h"
#include "csv.h"
#include <vector>

Pokedex::Pokedex(const std::string& nomFichier) : PokemonVector()
{
    std::vector<std::vector<std::string>> csvFile = lireCSV(nomFichier);
    csvFile.erase(csvFile.begin());
    for (std::vector<std::string> pokemonData: csvFile)
    {
        int id = std::stoi(pokemonData[0]);
        std::string name = pokemonData[1];
        double HP = std::stod(pokemonData[5]);
        double attack = std::stod(pokemonData[6]);
        double defense = std::stod(pokemonData[7]);
        Pokemon pokemon(id, name, 0, HP, HP, attack, defense);
        pokemons.push_back(pokemon);
    };

}

Pokedex::~Pokedex()
{

}

Pokedex* Pokedex::instance{nullptr};
Pokedex* Pokedex::getInstance(const std::string& nomFichier)
{

    if (instance == nullptr)
    {
        instance = new Pokedex(nomFichier);
    }

    else
    {
        std::cout<<"Instance has already been created"<<std::endl;
    }
    return instance;
}


Pokemon Pokedex::getCloneById(int id)
{
    return Pokemon(getCloneById(id));
}

Pokemon Pokedex::getCloneByName(const std::string name)
{
    return Pokemon(getCloneByName(name));
}

