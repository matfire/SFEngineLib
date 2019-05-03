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
    Sprite *trees1 = _scenes.at(_currentScene)->getSprite("trees1");
    Sprite *mountain_fair1 = _scenes.at(_currentScene)->getSprite("mountain far1");
    Sprite *mountain1 = _scenes.at(_currentScene)->getSprite("mountain1");

//  moving foreground trees
    fg_trees1->move(-1000 * elapsedTime, 0);

//  moving background trees

    trees1->move(-500 * elapsedTime, 0);

//  moving foreground mountains
    mountain1->move(-8 *elapsedTime, 0);

//  moving background mountains
    mountain_fair1->move(-4 * elapsedTime, 0);

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

    scene1->addSpriteToScene("mountain1", new Sprite("parallax-mountain-mountains"))->setWindow(&_window);

    scene1->addSpriteToScene("trees1", new Sprite("parallax-mountain-trees"))->setWindow(&_window);

    scene1->addSpriteToScene("foreground trees1", new Sprite("parallax-mountain-foreground-trees"))->setWindow(&_window);

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
    mountain_fair1->makeParallax(2);
    scene1->addToRenderOrder("mountain far1");

    //set mountains
    Sprite *mountain = scene1->getSprite("mountain1");
    mountain->setFullscreen();
    mountain->makeParallax(2);
    scene1->addToRenderOrder("mountain1");
    //set trees
    Sprite *trees1 = scene1->getSprite("trees1");
    trees1->setFullscreen();
    trees1->makeParallax(2);
    scene1->addToRenderOrder("trees1");

    //set foreground trees
    Sprite *fg_trees1 = scene1->getSprite("foreground trees1");
    fg_trees1->setFullscreen();
    fg_trees1->makeParallax(3);
    scene1->addToRenderOrder("foreground trees1");
//    scene1->addToRenderOrder("player");

    // set title text
    Sprite *main_text = scene1->getSprite("main text");
    main_text->setPosition(960 - main_text->getSizeX() / 2, 540);
    scene1->addToRenderOrder("main text");
    changeScene("scene 1");
}