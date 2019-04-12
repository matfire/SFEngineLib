//
// Created by matteo on 10/04/19.
//

#ifndef SFENGINE_ENGINE_H
#define SFENGINE_ENGINE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sprite.h"
#include "Scene.h"

class Engine {

public:
    Engine();
    ~Engine();
    void start(int width, int height, std::string name);
    void run();
    void addScene(std::string name, Scene *scene);
    sf::Event getEvent(){return _lastEvent;};
    virtual bool onUserCreate() = 0;
    virtual bool onUserUpdate(float elapsedTime) = 0;
    void handleEvents();
    void changeScene(std::string name);
    Scene *getScene(std::string name);
    Scene *getCurrentScene(){ return _scenes.at(_currentScene);};
protected:
    sf::RenderWindow _window;
    int _height;
    int _width;
    std::string _currentScene;
    sf::Event _lastEvent;
    std::map<std::string, Scene*> _scenes;
};


#endif //SFENGINE_ENGINE_H
