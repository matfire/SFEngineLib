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
    void move(sf::Vector2f movement){move(movement.x, movement.y);}
    void setInterval(sf::Time frameTime){_frameTime = frameTime;};
    void setAnimation(const Animation &animation) {
        m_animation = &animation;
        _currentFrame = 0;
        setFrame(_currentFrame);
    }
    void setFrame(size_t newFrame) {
        if (m_animation)
            {
                //calculate new vertex positions and texture coordiantes
                sf::IntRect rect = m_animation->getFrame(newFrame);
                updateRect(rect.left, rect.top, rect.width, rect.height);
            }
    }
    void update(sf::Time deltaTime) {
        _currentTime += deltaTime;

        // if current time is bigger then the frame time advance one frame
        if (_currentTime >= _frameTime)
        {
            // reset time, but keep the remainder
            _currentTime = sf::microseconds(_currentTime.asMicroseconds() % _frameTime.asMicroseconds());

            // get next Frame index
            if (_currentFrame + 1 < m_animation->getSize())
                _currentFrame++;
            else
            {
                // animation has ended
                _currentFrame = 0; // reset to start
            }
            // set the current frame, not reseting the time
            setFrame(_currentFrame);
        }
    }
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
    float getSpeed(){return (_speed);};
protected:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _text;
    sf::Font _font;
    sf::IntRect _displayRect;
    sf::RenderWindow *_window;
    sf::Time _frameTime;
    sf::Time _currentTime;
    std::size_t _currentFrame;
    bool _isText;
    bool _parallax;
    std::vector<sf::Sprite>_paras;
    const Animation* m_animation;
    float _speed;
};


#endif //SFENGINE_SPRITE_H

