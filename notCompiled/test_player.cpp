#include "Trainer.h"
#include <iostream>


int main() {
    Trainer ash(1, "Ash", "../sources/ash_sprite.png");
    std::cout << "Trainer ID: " << ash.getId() << std::endl;
    std::cout << "Trainer Name: " << ash.getName() << std::endl;
    return 0;
}