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
        defense(defense) {};


Pokemon::Pokemon(const Pokemon &base):
        id(base.id),
        name(base.name),
        evolution(base.evolution),
        maxHP(base.maxHP),
        HP(base.HP),
        attack(base.attack),
        defense(base.defense){};

Pokemon::~Pokemon()
            {
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
    std::cout<<"|"<<this->id<<"|"<<this->name<<"|"<<std::endl;
}







