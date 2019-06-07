//
// Created by matteo on 10/04/19.
//

#ifndef SFENGINE_SCENE_H
#define SFENGINE_SCENE_H


#include <string>
#include <map>
#include <list>
#include "Sprite.h"
#include "AnimatedSprite.hpp"

class Scene {
public:
    Scene(std::string name, sf::RenderWindow *window);
    ~Scene();
    AnimatedSprite *addSpriteToScene(std::string name, AnimatedSprite *sprite);
    void addToRenderOder(AnimatedSprite *sprite){_renderOrder.push_back(sprite);};
    void addToRenderOrder(std::string name);
    void render();
    AnimatedSprite *getSprite(std::string);
private:
    std::string _name;
    std::map<std::string, AnimatedSprite*> _sprites;
    std::list<AnimatedSprite *> _renderOrder;
    sf::RenderWindow *_window;
};


#endif //SFENGINE_SCENE_H
