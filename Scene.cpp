//
// Created by matteo on 10/04/19.
//

#include "Scene.h"

Scene::Scene(std::string name, sf::RenderWindow *window) {
    _name = name;
    _window = window;
}

Scene::~Scene() {

}

AnimatedSprite *Scene::addSpriteToScene(std::string name, AnimatedSprite *sprite) {
    _sprites.emplace(name, sprite);
    return _sprites.at(name);
}

AnimatedSprite *Scene::getSprite(std::string name) {
    try {
        _sprites.at(name);
    } catch(...) {
        throw std::runtime_error("Could not find sprite named " + name + " in scene " + _name);
    }
    return _sprites.at(name);
}

void Scene::render() {
    for (auto a: _renderOrder) {
        _window->draw(*a);
    }
}

void Scene::addToRenderOrder(std::string name) {
    try {
        _sprites.at(name);
    } catch (...) {
        throw std::runtime_error("Could not find sprite named " + name + " in scene " + _name);
    }
    _renderOrder.push_back(_sprites.at(name));
}