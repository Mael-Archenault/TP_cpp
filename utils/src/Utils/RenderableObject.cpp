
#include "Utils/RenderableObject.h"
#include "Utils/TextureManager.h"
#include <iostream>

void RenderableObject::render(sf::RenderWindow &window, sf::Vector2f position)
{
    sprite.setPosition(position);
    window.draw(sprite);
}

void RenderableObject::scale(float scaleX, float scaleY)
{
    sprite.setScale(scaleX, scaleY);
}

int RenderableObject::getWidth()
{
    return sprite.getGlobalBounds().width;
}

int RenderableObject::getHeight()
{
    return sprite.getGlobalBounds().height;
}

void RenderableObject::setSprite(std::string spritePath)
{
    texture = TextureManager::getInstance().loadTexture(spritePath);
    sprite.setTexture(*texture);
}