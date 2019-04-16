//
// Created by matteo on 16/04/19.
//

#include "assetManager.h"


void assetManager::loadTexture(std::string name, std::string path) {
    if (_textures.find(name) != _textures.end())
        throw std::runtime_error("texture " + name + " already exists");
    sf::Texture newTexture;
    if (!newTexture.loadFromFile(path)) {
        throw std::runtime_error("could not load texture " + name + " from path " + path);
    }
    _textures.emplace(name, new sf::Texture(newTexture));
    std::cout << "loaded texture " << name << " from " << path << std::endl;
}

sf::Texture *assetManager::getTexture(std::string name) {
    try {
        _textures.at(name);
    } catch (...) {
        throw std::runtime_error("texture with name " + name + " could not be found in loaded textures array" );
    }
    std::cout << "requested texture " << name << std::endl;
    return _textures.at(name);
}