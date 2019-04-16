//
// Created by matteo on 10/04/19.
//

#include <stdexcept>
#include "Sprite.h"
#include "assetManager.h"

Sprite::~Sprite() {
    _window = nullptr;
}

Sprite::Sprite() {
    _isText = false;
    _window = nullptr;
}

Sprite::Sprite(std::string textureName) {
    _window = nullptr;
    _isText = false;
    sf::Texture *texture = assetManager::get().getTexture(textureName);
    _sprite.setTexture(*texture);

}

Sprite::Sprite(sf::Font &font, std::string text, int size): _text(text, font, size) {
    _isText = true;
    _window = nullptr;
}

void Sprite::render() {
    if (_window == nullptr) {
        throw std::runtime_error("Did you forget to load the window on a Sprite?");
    }
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

void Sprite::setFullscreen() {
    if (_window == nullptr) {
        throw std::runtime_error("Please set the rendering window before calling setFullscreen");
    }
    if (_isText) {
        throw std::runtime_error("setFullscreen should not be used on text");
    }
    _sprite.setScale((float)_window->getSize().x/ _sprite.getLocalBounds().width,
                     (float)_window->getSize().y/ _sprite.getLocalBounds().height);
}