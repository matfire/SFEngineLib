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
    bg->move(0, -1 * elapsedTime / 1000);
    return true;
}

bool TestEngine::onUserCreate() {

    Scene *scene1;

    addScene("scene 1", new Scene("Scene 1"));
    scene1 = getScene("scene 1");
    scene1->addSpriteToScene("bg", new Sprite("./bg.jpg"));
    scene1->getSprite("bg")->setWindow(&_window);
    scene1->addToRenderOrder("bg");
    changeScene("scene 1");
}