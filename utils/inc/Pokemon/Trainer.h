
#ifndef TRAINER_H
#define TRAINER_H
#include "Utils/RenderableObject.h"
#include "Pokemon/PokemonParty.h"
#include "Pokemon/PokemonAttack.h"

class Trainer : public RenderableObject
{
protected:
    int id;
    std::string name;
    PokemonAttack attackTeam;

    sf::Vector2f position;
    int spriteWidth;
    int spriteHeight;
    int scaleFactor;

public:
    Trainer(int id, const std::string &name, const std::string &textureFile, sf::Vector2f position);

    int getId() const;
    std::string getName() const;
    sf::Vector2f getPosition();
    int getSpriteWidth();
    int getSpriteHeight();
    PokemonAttack &getAttackTeam();
    void setPosition(sf::Vector2f new_position);
};

#endif