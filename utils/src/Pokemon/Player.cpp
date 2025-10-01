#include "Pokemon/Player.h"

Player::Player(int id, const std::string &name, const std::string &textureFile, sf::Vector2f position) : Trainer(id, name, textureFile, position)
{

    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setScale((float)scaleFactor, (float)scaleFactor);

    speed = 5;
    lastFrameChangeTime = 0.0f;
    moving = false;
}

void Player::update(float deltaTime)
{
    if (moving == false)
    {
        currentFrame = 0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction * spriteHeight, spriteWidth, spriteHeight));
    }
    else if (this->lastFrameChangeTime >= 0.2f)
    {
        currentFrame = (currentFrame + 1) % 3; // 3 frames spritesheet
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction * spriteHeight, spriteWidth, spriteHeight));
        lastFrameChangeTime = 0.0f;
    }
    else
    {
        lastFrameChangeTime += deltaTime;
    }
}

void Player::goDown()
{
    if (this->moving == false)
    {
        this->moving = true;
    }
    this->position = this->position + sf::Vector2f(0, this->speed);
    if (direction != 1)
    {
        direction = 1;
        currentFrame = 0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction * spriteHeight, spriteWidth, spriteHeight));
    }
}

void Player::goUp()
{
    if (this->moving == false)
    {
        this->moving = true;
    }
    this->position = this->position + sf::Vector2f(0, -this->speed);
    if (direction != 0)
    {
        direction = 0;
        currentFrame = 0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction * spriteHeight, spriteWidth, spriteHeight));
    }
}

void Player::goLeft()
{
    if (this->moving == false)
    {
        this->moving = true;
    }
    this->position = this->position + sf::Vector2f(-this->speed, 0);
    if (direction != 2)
    {
        direction = 2;
        currentFrame = 0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction * spriteHeight, spriteWidth, spriteHeight));
    }
}

void Player::goRight()
{
    if (this->moving == false)
    {
        this->moving = true;
    }
    this->position = this->position + sf::Vector2f(this->speed, 0);
    if (direction != 3)
    {
        direction = 3;
        currentFrame = 0;
        sprite.setTextureRect(sf::IntRect(currentFrame * spriteWidth, direction * spriteHeight, spriteWidth, spriteHeight));
    }
}

void Player::setMoving(bool new_state)
{
    moving = new_state;
}
