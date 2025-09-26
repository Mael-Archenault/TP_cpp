#include "TextureManager.h"
#include <iostream>

TextureManager* TextureManager::instance = nullptr;

TextureManager& TextureManager::getInstance() {
    if (instance == nullptr) {
        instance = new TextureManager();
    }
    return *instance;
}

sf::Texture* TextureManager::loadTexture(const std::string& filename) {
    // Check if texture already exists
    auto it = textures.find(filename);
    if (it != textures.end()) {
        return it->second.get();
    }
    
    // Load new texture
    auto texture = std::make_unique<sf::Texture>();
    if (!texture->loadFromFile(filename)) {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        return nullptr;
    }
    
    sf::Texture* texturePtr = texture.get();
    textures[filename] = std::move(texture);
    return texturePtr;
}

sf::Texture* TextureManager::getTexture(const std::string& filename) {
    auto it = textures.find(filename);
    if (it != textures.end()) {
        return it->second.get();
    }
    return nullptr;
}

void TextureManager::unloadTexture(const std::string& filename) {
    textures.erase(filename);
}

void TextureManager::unloadAll() {
    textures.clear();
}

TextureManager::~TextureManager() {
    unloadAll();
}