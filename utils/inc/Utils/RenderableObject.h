
#ifndef TP_CPP_RENDERABLEOBJECT_H
#define TP_CPP_RENDERABLEOBJECT_H

#include <SFML/Graphics.hpp>

class RenderableObject
{

protected:
    sf::Sprite sprite;

public:
    sf::Texture *texture;
    RenderableObject() {};
    int getWidth();
    int getHeight();
    void setSprite(std::string spritePath);

    void scale(float scaleX, float scaleY);
    void render(sf::RenderWindow &window, sf::Vector2f position);
};

#endif // TP_CPP_RENDERABLEOBJECT_H