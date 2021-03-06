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




// class WrapperSprite: public sf::Drawable, public sf::Transformable {

// }

class Scene {
public:
    Scene(std::string name, sf::RenderWindow *window);
    ~Scene();
    Sprite *addSpriteToScene(std::string name, Sprite *sprite);
    void addToRenderOder(Sprite *sprite){_renderOrder.push_back(sprite);};
    void addToRenderOrder(std::string name);
    void render();
    Sprite *getSprite(std::string);
private:
    std::string _name;
    std::map<std::string, Sprite*> _sprites;
    std::list<Sprite *> _renderOrder;
    sf::RenderWindow *_window;
};


#endif //SFENGINE_SCENE_H
 