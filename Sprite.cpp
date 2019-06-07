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
    _parallax = false;
}

Sprite::Sprite(std::string textureName) {
    _window = nullptr;
    _isText = false;
    _parallax = false;
    sf::Texture *texture = assetManager::get().getTexture(textureName);
    _texture = *texture;
    _sprite.setTexture(*texture);

}

Sprite::Sprite(std::string fontName, std::string text, int size) {
    sf::Font *font = assetManager::get().getFont(fontName);
    _text.setFont(*font);
    _text.setString(text);
    _text.setCharacterSize(size);
    _isText = true;
    _window = nullptr;
    _parallax = false;
}

void Sprite::render() {
    if (_window == nullptr) {
        throw std::runtime_error("Did you forget to load the window on a Sprite?");
    }
    if (_isText) {
        _window->draw(_text);
    } else if (_parallax) {
        _window->draw(_sprite);
        for (auto a: _paras) {
            _window->draw(a);
        }
    } else {
        _window->draw(_sprite);
    }
}

void Sprite::move(float x, float y) {
    if (_isText) {
        _text.move({x, y});
    } else if (_parallax) {
        _sprite.move({x, y});
        if (_sprite.getPosition().x + getSizeX() < 0) {
            _sprite.setPosition(getSizeX(), 0);
        }
        for (int i = 0; i < _paras.size(); i++) {
            _paras[i].move({x, y});
            if (_paras[i].getPosition().x + getSizeX() < 0) {
                _paras[i].setPosition(getSizeX(), _sprite.getPosition().y);
            }
        }

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

float Sprite::getSizeX() {
    if (_isText)
        return (_text.getGlobalBounds().width);
    return _sprite.getTexture()->getSize().x * _sprite.getScale().x - 10;
}

float Sprite::getSizeY() {
    if (_isText)
        return (_text.getGlobalBounds().height);
    return _sprite.getTexture()->getSize().y * _sprite.getScale().y;
}

bool Sprite::collision(Sprite *sprite) {
    return _sprite.getGlobalBounds().intersects(sprite->getSprite()->getGlobalBounds());
}

void Sprite::makeParallax(int nb) {
    if (_window == nullptr)
        throw std::runtime_error("Please set the rendering window before calling makeParallax");
    _parallax = true;
    for (int i = 0; i < nb; i++) {
        sf::Sprite newSprite;
        newSprite.setTexture(_texture);
        newSprite.setPosition(_sprite.getPosition().x + getSizeX() * (i + 1), 0);
        newSprite.setScale(_sprite.getScale());
        _paras.push_back(newSprite);
    }
}