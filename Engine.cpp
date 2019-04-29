//
// Created by matteo on 10/04/19.
//

#include "Engine.h"
#include "assetManager.h"

Engine::Engine() {
    _height = 0;
    _width = 0;
}

Engine::~Engine() {
}

void Engine::handleEvents() {
    while (_window.pollEvent(_lastEvent)) {
        if (_lastEvent.type == sf::Event::Closed)
            _window.close();
    }
}

void Engine::start(unsigned int width, unsigned int height, std::string name) {
    _width = width;
    _height = height;
    _window.create({width, height}, name);
}

void Engine::run() {
    sf::Clock timer;
    onUserCreate();
    while (_window.isOpen()) {
        _window.clear();
        handleEvents();
        onUserUpdate(timer.getElapsedTime().asMicroseconds());
        _scenes.at(_currentScene)->render();
        _window.display();
        timer.restart();
    }
}

void Engine::addScene(std::string name, Scene *scene) {
    _scenes.emplace(name, scene);
}

void Engine::changeScene(std::string name) {
    try {
        _scenes.at(name);
    } catch (...) {
        throw std::runtime_error("Could not find requested scene. Have you loaded it?");
    }
    _currentScene = name;
}

Scene *Engine::getScene(std::string name) {
    try {
        _scenes.at(name);
    } catch (...) {
        throw std::runtime_error("Could not find request scene. Have you loaded it?");
    }
    return _scenes.at(name);

}