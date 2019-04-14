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
    Sprite(sf::Font &font, std::string text, int size);
    ~Sprite();
    virtual void render();
    void setWindow(sf::RenderWindow *window){_window = window;};
    void move(float x, float y);
    void setPosition(float x, float y);
    void updateRect(int x, int y, int width, int height);
    void setText(sf::Font &font, std::string text, int fontSize);
    float getX(){return _sprite.getPosition().x;};
    float getY(){return _sprite.getPosition().y;};
    sf::Sprite *getSprite(){return &_sprite;};
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _text;
    sf::Font _font;
    sf::IntRect _displayRect;
    sf::RenderWindow *_window;
    bool _isText;
};


#endif //SFENGINE_SPRITE_H
