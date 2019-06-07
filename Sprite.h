//
// Created by matteo on 10/04/19.
//

#ifndef SFENGINE_SPRITE_H
#define SFENGINE_SPRITE_H


#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "AnimatedSprite.hpp"

class Sprite {
public:
    Sprite();
    Sprite(std::string textureName);
    Sprite(std::string fontName, std::string text, int size);
    ~Sprite();
    virtual void render();
    void setWindow(sf::RenderWindow *window){_window = window;};
    void move(float x, float y);
    void setPosition(float x, float y);
    void updateRect(int x, int y, int width, int height);
    void setText(sf::Font &font, std::string text, int fontSize);
    void setFullscreen();
    float getX(){return _sprite.getPosition().x;};
    float getY(){return _sprite.getPosition().y;};
    float getSizeX();
    float getSizeY();
    sf::Sprite *getSprite(){return &_sprite;};
    bool collision(Sprite *sprite);
    void makeParallax(int nb);
protected:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _text;
    sf::Font _font;
    sf::IntRect _displayRect;
    sf::RenderWindow *_window;
    bool _isText;
    bool _parallax;
    std::vector<sf::Sprite>_paras;
};


#endif //SFENGINE_SPRITE_H