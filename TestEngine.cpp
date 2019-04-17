//
// Created by matteo on 12/04/19.
//

#include "TestEngine.h"
#include "assetManager.h"

TestEngine::TestEngine() : Engine() {

}

TestEngine::~TestEngine() {

}

bool TestEngine::onUserUpdate(float elapsedTime) {
    Sprite *fg_trees1 = _scenes.at(_currentScene)->getSprite("foreground trees1");
    Sprite *fg_trees2 = _scenes.at(_currentScene)->getSprite("foreground trees2");
    Sprite *fg_trees3 = _scenes.at(_currentScene)->getSprite("foreground trees3");
    Sprite *trees1 = _scenes.at(_currentScene)->getSprite("trees1");
    Sprite *trees2 = _scenes.at(_currentScene)->getSprite("trees2");
    Sprite *mountain_fair1 = _scenes.at(_currentScene)->getSprite("mountain far1");
    Sprite *mountain_fair2 = _scenes.at(_currentScene)->getSprite("mountain far2");
    Sprite *mountain1 = _scenes.at(_currentScene)->getSprite("mountain1");
    Sprite *mountain2 = _scenes.at(_currentScene)->getSprite("mountain2");

    //moving foreground trees
    if (fg_trees1->getX() + fg_trees1->getSizeX() < 0) {
        fg_trees1->setPosition(fg_trees1->getSizeX(), 0);
    } else {
        fg_trees1->move(-20 * elapsedTime / 1000, 0);
    }
    if (fg_trees2->getX() + fg_trees1->getSizeX() < 0) {
        fg_trees2->setPosition(fg_trees1->getSizeX(), 0);
    } else {
        fg_trees2->move(-20 * elapsedTime / 1000, 0);
    }
    if (fg_trees3->getX() + fg_trees1->getSizeX() < 0) {
        fg_trees3->setPosition(fg_trees1->getSizeX(), 0);
    } else {
        fg_trees3->move(-20 * elapsedTime / 1000, 0);
    }

    //moving background trees
    if (trees1->getX() + trees1->getSizeX() < 0) {
        trees1->setPosition(trees1->getSizeX(), 0);
    } else {
        trees1->move(-5 * elapsedTime / 1000, 0);
    }
    if (trees2->getX() + trees2->getSizeX() < 0) {
        trees2->setPosition(trees2->getSizeX(), 0);
    } else {
        trees2->move(-5 * elapsedTime / 1000, 0);
    }

    //moving foreground mountains
    if (mountain1->getX() + mountain1->getSizeX() < 0) {
        mountain1->setPosition(mountain1->getSizeX(), 0);
    } else {
        mountain1->move(-0.2 * elapsedTime / 1000, 0);
    }
    if (mountain2->getX() + mountain2->getSizeX() < 0) {
        mountain2->setPosition(mountain1->getSizeX(), 0);
    } else {
        mountain2->move(-0.2 * elapsedTime / 1000, 0);
    }


    // moving background mountains
    if (mountain_fair1->getX() + mountain_fair1->getSizeX() < 0) {
        mountain_fair1->setPosition(mountain_fair1->getSizeX(), 0);
    } else {
        mountain_fair1->move(-0.02 * elapsedTime / 1000, 0);
    }
    if (mountain_fair2->getX() + mountain_fair2->getSizeX() < 0) {
        mountain_fair2->setPosition(mountain_fair2->getSizeX(), 0);
    } else {
        mountain_fair2->move(-0.02 * elapsedTime / 1000, 0);
    }
    return true;
}

bool TestEngine::onUserCreate() {

    //load assets
    assetManager::get().loadTexture("parallax-mountain-bg", "../assets/parallax-mountain-bg.png");
    assetManager::get().loadTexture("parallax-mountain-montain-far", "../assets/parallax-mountain-montain-far.png");
    assetManager::get().loadTexture("parallax-mountain-mountains", "../assets/parallax-mountain-mountains.png");
    assetManager::get().loadTexture("parallax-mountain-trees", "../assets/parallax-mountain-trees.png");
    assetManager::get().loadTexture("parallax-mountain-foreground-trees", "../assets/parallax-mountain-foreground-trees.png");
    assetManager::get().loadFont("emulogic", "../assets/emulogic.ttf");

    Scene *scene1;
    addScene("scene 1", new Scene("Scene 1"));
    scene1 = getScene("scene 1");
    scene1->addSpriteToScene("bg", new Sprite("parallax-mountain-bg"));

    scene1->addSpriteToScene("mountain far1", new Sprite("parallax-mountain-montain-far"))->setWindow(&_window);
    scene1->addSpriteToScene("mountain far2", new Sprite("parallax-mountain-montain-far"))->setWindow(&_window);

    scene1->addSpriteToScene("mountain1", new Sprite("parallax-mountain-mountains"))->setWindow(&_window);
    scene1->addSpriteToScene("mountain2", new Sprite("parallax-mountain-mountains"))->setWindow(&_window);

    scene1->addSpriteToScene("trees1", new Sprite("parallax-mountain-trees"))->setWindow(&_window);
    scene1->addSpriteToScene("trees2", new Sprite("parallax-mountain-trees"))->setWindow(&_window);

    scene1->addSpriteToScene("foreground trees1", new Sprite("parallax-mountain-foreground-trees"))->setWindow(&_window);
    scene1->addSpriteToScene("foreground trees2", new Sprite("parallax-mountain-foreground-trees"))->setWindow(&_window);
    scene1->addSpriteToScene("foreground trees3", new Sprite("parallax-mountain-foreground-trees"))->setWindow(&_window);

    scene1->addSpriteToScene("main text", new Sprite("emulogic", "Welcome to the demo", 30))->setWindow(&_window);
    // add player
    //scene1->addSpriteToScene("player", new Sprite("../assets/player.png"))->setWindow(&_window);
    //Sprite *player = scene1->getSprite("player");
    //player->updateRect(0,0,70,70);


    // set bg
    scene1->getSprite("bg")->setWindow(&_window);
    scene1->getSprite("bg")->setFullscreen();
    scene1->addToRenderOrder("bg");
    // set gar mountains
    Sprite *mountain_fair1 = scene1->getSprite("mountain far1");
    mountain_fair1->setFullscreen();
    scene1->addToRenderOrder("mountain far1");
    Sprite *mountain_fair2 = scene1->getSprite("mountain far2");
    mountain_fair2->setFullscreen();
    mountain_fair2->setPosition(mountain_fair1->getSizeX(), 0);
    scene1->addToRenderOrder("mountain far2");

    //set mountains
    Sprite *mountain = scene1->getSprite("mountain1");
    mountain->setFullscreen();
    scene1->addToRenderOrder("mountain1");
    Sprite *mountain2 = scene1->getSprite("mountain2");
    mountain2->setFullscreen();
    mountain2->setPosition(mountain->getSizeX(), 0);
    scene1->addToRenderOrder("mountain2");
    //set trees
    Sprite *trees1 = scene1->getSprite("trees1");
    trees1->setFullscreen();
    scene1->addToRenderOrder("trees1");
    Sprite *trees2 = scene1->getSprite("trees2");
    trees2->setFullscreen();
    trees2->setPosition(trees1->getSizeX(), 0);
    scene1->addToRenderOrder("trees2");

    //set foreground trees
    Sprite *fg_trees1 = scene1->getSprite("foreground trees1");
    fg_trees1->setFullscreen();
    scene1->addToRenderOrder("foreground trees1");
    Sprite *fg_trees2 = scene1->getSprite("foreground trees2");
    fg_trees2->setFullscreen();
    fg_trees2->setPosition(fg_trees2->getSizeX(), 0);
    scene1->addToRenderOrder("foreground trees2");
    Sprite *fg_trees3 = scene1->getSprite("foreground trees3");
    fg_trees3->setFullscreen();
    fg_trees3->setPosition(fg_trees2->getX(), 0);
    scene1->addToRenderOrder("foreground trees3");
    //scene1->addToRenderOrder("player");

    // set title text
    Sprite *main_text = scene1->getSprite("main text");
    main_text->setPosition(960 - main_text->getSizeX() / 2, 540);
    scene1->addToRenderOrder("main text");
    changeScene("scene 1");
}