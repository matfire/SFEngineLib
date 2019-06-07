#include "DuckDuckDie.h"

DuckEngine::DuckEngine() : Engine() {}

DuckEngine::~DuckEngine() {}


bool DuckEngine::onUserCreate() {

	//load assets

	assetManager::get().loadTexture("normal duck", "./assets/ducks.png");
	assetManager::get().loadTexture("hard duck", "./assets/ducks_hard.png");


	AnimatedSprite *duck1 = new NormalDuck();
	AnimatedSprite *duck2 = new HardDuck();
	duck1->setPosition({100, 100});
	duck2->setPosition({200, 200});
	addScene("main", new Scene("main", &_window));

	changeScene("main");
	Scene *main = getScene("main");
	main->addSpriteToScene("duck1", duck1);
	main->addSpriteToScene("duck2", duck2);
	main->addToRenderOrder("duck1");
	main->addToRenderOrder("duck2");
	return true;
}


bool DuckEngine::onUserUpdate(float elapsedTime) {
	AnimatedSprite *duck1 = getCurrentScene()->getSprite("duck1");
	AnimatedSprite *duck2 = getCurrentScene()->getSprite("duck2");
	duck1->update(_timer.getElapsedTime());
	duck2->update(_timer.getElapsedTime());
	return true;
}