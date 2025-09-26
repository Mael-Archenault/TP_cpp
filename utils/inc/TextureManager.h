#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>

class TextureManager {
private:
    static TextureManager* instance;
    std::map<std::string, std::unique_ptr<sf::Texture>> textures;
    
    TextureManager() = default;

public:
    static TextureManager& getInstance();
    
    sf::Texture* loadTexture(const std::string& filename);
    sf::Texture* getTexture(const std::string& filename);
    void unloadTexture(const std::string& filename);
    void unloadAll();
    
    ~TextureManager();
};

#endif // TEXTUREMANAGER_H