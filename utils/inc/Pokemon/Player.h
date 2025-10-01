#ifndef PLAYER_H
#define PLAYER_H

#include "Trainer.h"
#include <SFML/Graphics.hpp>

class Player : public Trainer
{
private:
    float lastFrameChangeTime;
    int currentFrame;
    int speed;
    int direction;
    bool moving;

public:
    Player(int id, const std::string &name, const std::string &textureFile, sf::Vector2f position);

    void setMoving(bool new_state);

    void update(float deltaTime);
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
};

#endif