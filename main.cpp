


/*#include "Pokemon.hpp"


int main(){
    Pokemon bulbizarre(0,"Bulbizarre", 10,4,1,1);
    Pokemon pikachu(0,"Pikachu", 10,2,0,1);



    bulbizarre.attackOther(pikachu);
    bulbizarre.attackOther(pikachu);
    bulbizarre.attackOther(pikachu);
    bulbizarre.attackOther(pikachu);
    bulbizarre.attackOther(pikachu);
    bulbizarre.attackOther(pikachu);
    bulbizarre.attackOther(pikachu);
}*/


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
}