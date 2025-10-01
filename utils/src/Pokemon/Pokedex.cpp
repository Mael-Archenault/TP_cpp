#include "Pokemon/Pokedex.h"
#include "Pokemon/Pokemon.h"
#include "Utils/csv.h"
#include <vector>

Pokedex::Pokedex(const std::string &nomFichier) : PokemonVector()
{
    std::vector<std::vector<std::string>> csvFile = lireCSV(nomFichier);
    csvFile.erase(csvFile.begin()); // first line is the column labels
    for (std::vector<std::string> pokemonData : csvFile)
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

Pokedex *Pokedex::instance{nullptr};
Pokedex *Pokedex::getInstance(const std::string &nomFichier)
{

    if (instance == nullptr)
    {
        instance = new Pokedex(nomFichier);
    }

    return instance;
}

Pokemon Pokedex::getCloneById(int id)
{
    return Pokemon(getById(id));
};

Pokemon Pokedex::getCloneByName(const std::string name)
{
    return Pokemon(getByName(name));
};

Pokemon Pokedex::getRandomPokemon()
{
    int maxIndex = pokemons.at(pokemons.size() - 1).getId();
    int randomIndex = rand() % maxIndex;
    return this->getCloneById(randomIndex);
}
