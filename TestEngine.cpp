//
// Created by matteo on 12/04/19.
//

#include "TestEngine.h"

TestEngine::TestEngine() : Engine() {

}

TestEngine::~TestEngine() {

}

bool TestEngine::onUserUpdate(float elapsedTime) {
    Sprite *bg = _scenes.at(_currentScene)->getSprite("bg");
    Sprite *text = _scenes.at(_currentScene)->getSprite("title text");
    bg->move(0, -1 * elapsedTime / 1000);
    text->move(1 * elapsedTime / 1000, 0);
    return true;
}

bool TestEngine::onUserCreate() {

    Scene *scene1;
    if (!_font.loadFromFile("./emulogic.ttf"))
        throw std::runtime_error("could not load font");
    addScene("scene 1", new Scene("Scene 1"));
    scene1 = getScene("scene 1");
    scene1->addSpriteToScene("bg", new Sprite("./bg.jpg"));
    scene1->addSpriteToScene("title text", new Sprite(_font, "Test", 20));
    scene1->getSprite("bg")->setWindow(&_window);
    scene1->getSprite("title text")->setWindow(&_window);
    scene1->addToRenderOrder("bg");
    scene1->addToRenderOrder("title text");
    changeScene("scene 1");
}