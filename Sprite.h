//
// Created by matteo on 10/04/19.
//

#ifndef SFENGINE_SPRITE_H
#define SFENGINE_SPRITE_H


#include <SFML/Graphics.hpp>

class Sprite {
public:
    Sprite();
    Sprite(std::string path);
    ~Sprite();
    virtual void render();
    void setWindow(sf::RenderWindow *window){_window = window;};
    void move(float x, float y);
    void setPosition(float x, float y);
    float getX(){return _sprite.getPosition().x;};
    float getY(){return _sprite.getPosition().y;};
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::IntRect _displayRect;
    sf::RenderWindow *_window;
    bool _rectSet;
};


#endif //SFENGINE_SPRITE_H
