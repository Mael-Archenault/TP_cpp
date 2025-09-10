

#include "Pokedex.h"
#include "PokemonParty.h"


int main(){
    Pokedex* pokedex = Pokedex::getInstance("/home/mael-archenault/Desktop/TP_cpp/pokedex.csv");
    Pokemon poke1 = pokedex->getCloneById(45);
    Pokemon poke2 = pokedex->getCloneById(60);
    PokemonParty party;
    party.addPokemonToParty(poke1);
    party.addPokemonToParty(poke2);

    party.removePokemonFromParty(poke1);

}




// Test SFML

/*
#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}*/