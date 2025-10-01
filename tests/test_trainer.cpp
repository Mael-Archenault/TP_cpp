#include "Pokemon/Trainer.h"
#include <iostream>


int main() {
    Trainer test(1, "Ash", "../sources/champions_sprites/1.png", sf::Vector2f(0,0));
    std::cout << "Trainer ID: " << test.getId() << std::endl;
    std::cout << "Trainer Name: " << test.getName() << std::endl;
    std::cout << "Trainer Position: "<< test.getPosition().x<<" "<<test.getPosition().y << std::endl;
    return 0;
}