#include <iostream>
#include "Pokemon.hpp"


Pokemon::Pokemon(const int id,
            const std::string name,
            const double hitPoint,
            const double attack,
            const double defense,
            const int generation):

            id(id),
            name(name),
            hitPoint(hitPoint),
            attack(attack),
            defense(defense),
            generation(generation){};


Pokemon::Pokemon(const Pokemon &base)

            {
                Pokemon(base.id, base.name, base.hitPoint, base.attack, base.defense, base.generation);
            }

Pokemon::~Pokemon()
            {
                std::cout<<"Destroyed"<<std::endl;
            };


void Pokemon::displayInfo() const{
            std::cout<<"id: "<<this->id<<std::endl;
            std::cout<<"name: "<<this->name<<std::endl;
            std::cout<<"hitPoint: "<<this->hitPoint<<std::endl;
            std::cout<<"attack: "<<this->attack<<std::endl;
            std::cout<<"defense: "<<this->defense<<std::endl;
            std::cout<<"generation: "<<this->generation<<std::endl;

        };


void Pokemon::attackOther(Pokemon &other) const{
    double damages = std::max(this->attack-other.getDefense(), (double)0);

    other.takeStrike(damages);

}



double Pokemon::getAttack() const{
    return this->attack;
}
double Pokemon::getDefense(){
    return this->defense;
}
double Pokemon::getHitPoint(){
    return this->hitPoint;
}

void Pokemon::takeStrike(double damages){
    if (this->hitPoint==0){
        std::cout<<this->name<<" is already dead, the attack is useless"<<std::endl;
        return;
    }
    std::cout<<this->name<<" is taking "<<damages<<" points of damages"<<std::endl;
    this->hitPoint = std::max(this->hitPoint - damages, (double)0);

    if (this->hitPoint==0){
        std::cout<<"Blurgh"<<std::endl;
    };
    return;
}




