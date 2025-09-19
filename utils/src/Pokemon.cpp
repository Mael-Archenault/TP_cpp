#include <iostream>
#include "Pokemon.h"



#include "csv.h"


/////////////////////////////
//////// Pokemon   /////////
///////////////////////////
Pokemon::Pokemon(int id,
             std::string name,
             int evolution,
             double maxHP,
             double HP,
             double attack,
             double defense):
        id(id),
        name(name),
        evolution(evolution),
        maxHP(maxHP),
        HP(HP),
        attack(attack),
        defense(defense)
{

    // Initializing rendering parameters (from RenderableObject Class)
    //std::string image_path = "/home/mael-archenault/Desktop/TP_cpp/sources/sprites/"+std::to_string(id)+".png";
    //texture.loadFromFile(image_path);
    //sprite.setTexture(texture);
};



Pokemon::Pokemon(const Pokemon &base):
        id(base.id),
        name(base.name),
        evolution(base.evolution),
        maxHP(base.maxHP),
        HP(base.HP),
        attack(base.attack),
        defense(base.defense)
{
    //texture = sf::Texture(base.texture);
    //sprite = sf::Sprite(base.sprite);
};

std::string Pokemon::getName()
{
    return this->name;
}

int Pokemon::getId()
{
    return this->id;
}

double Pokemon::heal(double amount)
{
    if (amount <= 0.0) return 0.0;
    double before = this->HP;
    this->HP = std::min(this->maxHP, this->HP + amount);
    return this->HP - before;
}

void Pokemon::display()
{
    std::cout<<"|"<<this->id<<"|"<<this->name<<"|"<<this->evolution<<"|"<<this->maxHP<<"|"<<this->HP<<"|"<<this->attack<<"|"<<this->defense<<"|"<<std::endl;
}







