//
// Created by matteo on 10/04/19.
//

#include <stdexcept>
#include "Sprite.h"

Sprite::~Sprite() {

}

Sprite::Sprite() {
    _isText = false;
}

Sprite::Sprite(std::string path) {
    _isText = false;
    if (!_texture.loadFromFile(path))
        throw std::runtime_error("Could not load texture from file " + path);
    _sprite.setTexture(_texture);

}

Sprite::Sprite(sf::Font &font, std::string text, int size): _text(text, font, size) {
    _isText = true;

}

void Sprite::render() {
    if (_isText) {
        _window->draw(_text);
    } else {
        _window->draw(_sprite);
    }
}

void Sprite::move(float x, float y) {
    if (_isText) {
        _text.move({x, y});
    } else
        _sprite.move({x, y});
}

void Sprite::setPosition(float x, float y)
{
    if (_isText) {
        _text.setPosition({x, y});
    } else
        _sprite.setPosition({x, y});
}

void Sprite::updateRect(int x, int y, int width, int height) {
    _displayRect.left = x;
    _displayRect.top = y;
    _displayRect.height = height;
    _displayRect.width = width;
    _sprite.setTextureRect(_displayRect);
}

void Sprite::setText(sf::Font &font, std::string text, int fontSize) {
    _isText = true;
    _font = font;
    _text.setFont(_font);
    _text.setString(text);
    _text.setCharacterSize(fontSize);
}