//
// Created by mael-archenault on 9/12/25.
//

#ifndef TP_CPP_RENDERABLEOBJECT_H
#define TP_CPP_RENDERABLEOBJECT_H

#include <SFML/Graphics.hpp>


class RenderableObject
{

protected:
sf::Sprite sprite;
public:
    sf::Texture* texture;
    RenderableObject(){};
    void scale(float scaleX, float scaleY);
    void reverseX();
    int getWidth();
    int getHeight();
    void render(sf::RenderWindow& window, sf::Vector2f position);

};


#endif //TP_CPP_RENDERABLEOBJECT_H