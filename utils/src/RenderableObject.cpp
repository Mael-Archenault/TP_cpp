
#include "RenderableObject.h"

void RenderableObject::render(sf::RenderWindow& window, sf::Vector2f position)
{    
    sprite.setPosition(position);
    window.draw(sprite);
}

void RenderableObject::scale(float scaleX, float scaleY){
    sprite.setScale(scaleX, scaleY);
}

int RenderableObject::getWidth(){
    return sprite.getGlobalBounds().width;
}

int RenderableObject::getHeight(){
    return sprite.getGlobalBounds().height;
}

void RenderableObject::reverseX(){
    sprite.scale(sf::Vector2f(-1.0f, 1.0f));
}