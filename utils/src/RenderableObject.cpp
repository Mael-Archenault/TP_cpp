
#include "RenderableObject.h"

void RenderableObject::render(sf::RenderWindow& window, sf::Vector2f position)
{    
    sprite.setPosition(position);
    window.draw(sprite);
}
