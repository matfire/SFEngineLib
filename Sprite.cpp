//
// Created by matteo on 10/04/19.
//

#include <stdexcept>
#include "Sprite.h"

Sprite::~Sprite() {

}

Sprite::Sprite() {
    _rectSet = false;
}

Sprite::Sprite(std::string path) {
    _rectSet = false;
    if (!_texture.loadFromFile(path))
        throw std::runtime_error("Could not load texture from file " + path);
    _sprite.setTexture(_texture);

}

void Sprite::render() {
    _window->draw(_sprite);
}

void Sprite::move(float x, float y) {
    _sprite.move({x, y});
}

void Sprite::setPosition(float x, float y)
{
    _sprite.setPosition({x, y});
}