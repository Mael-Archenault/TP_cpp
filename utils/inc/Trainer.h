
#ifndef TRAINER_H
#define TRAINER_H
#include "RenderableObject.h"
#include "PokemonParty.h"
#include "PokemonAttack.h"

class Trainer: public RenderableObject
{
    private:
        int id;
        std::string name;
        float lastFrameChangeTime = 0.0f;
        int currentFrame;
        sf::Vector2f position;
        int speed;
        int direction;

        int spriteWidth = 32;
        int spriteHeight = 33;

        int scale = 4;

        bool moving = false;


        PokemonAttack attackTeam;
        PokemonParty bagTeam;

    public:
        Trainer(int id, const std::string& name, const std::string& textureFile, sf::Vector2f position);
        ~Trainer(){};

        void update(float deltaTime);


        int getId() const;
        std::string getName() const;
        sf::Vector2f getPosition();
        int getSpriteWidth(){
            return spriteWidth*scale;
        }
        int getSpriteHeight(){
            return spriteHeight*scale;
        }

        PokemonAttack& getAttackTeam();

        void setMoving(bool new_state);
        void setPosition(sf::Vector2f new_position);


        void goUp();
        void goDown();
        void goLeft();
        void goRight();
};


#endif