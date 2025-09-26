#include <iostream>
#include "Pokemon.h"
#include "TextureManager.h"


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

    //Initializing rendering parameters (from RenderableObject Class)
    std::string image_path = "../sources/sprites/"+std::to_string(id)+".png";
    texture = TextureManager::getInstance().loadTexture(image_path);
    if (texture) {
        sprite.setTexture(*texture);
    }
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
    texture = base.texture;
    sprite = base.sprite;
};

std::string Pokemon::getName()
{
    return this->name;
}

int Pokemon::getId()
{
    return this->id;
}

void Pokemon::display()
{
    std::cout<<"|"<<this->id<<"|"<<this->name<<"|"<<this->evolution<<"|"<<this->maxHP<<"|"<<this->HP<<"|"<<this->attack<<"|"<<this->defense<<"|"<<std::endl;
}







