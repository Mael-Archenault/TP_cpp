

#include "Pokedex.h"



int main(){
    Pokedex* test = Pokedex::getInstance("/home/mael-archenault/Desktop/TP_cpp/pokedex.csv");
    Pokedex* test2 = Pokedex::getInstance("/home/mael-archenault/Desktop/TP_cpp/pokedex.csv");
    std::cout<<(test == test2)<<std::endl;

    test->displayByName();

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