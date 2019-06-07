#include "DuckDuckDie.h"
#include <random>

DuckEngine::DuckEngine() : Engine() {}

DuckEngine::~DuckEngine() {}


bool DuckEngine::onUserCreate() {

	//load assets
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 200);
	int offset = 10;
	assetManager::get().loadTexture("normal duck", "./assets/ducks.png");
	assetManager::get().loadTexture("hard duck", "./assets/ducks_hard.png");
	assetManager::get().loadTexture("bg", "./assets/bg.png");
	addScene("main", new Scene("main", &_window));

	changeScene("main");
	Scene *main = getScene("main");
	for (int i = 0; i < 10; i++) {
		_normalDucks.push_back(new NormalDuck());
		_hardDucks.push_back(new HardDuck());
	}
	Animation bg_animation;
	bg_animation.setSpriteSheet(*assetManager::get().getTexture("bg"));
	sf::Vector2u bg_size = bg_animation.getSpriteSheet()->getSize();
	bg_animation.addFrame(sf::IntRect(0, 0,bg_size.x,bg_size.y));
	AnimatedSprite *bg = new AnimatedSprite(sf::seconds(0.2), true, false);
	bg->setAnimation(bg_animation);
	main->addSpriteToScene("bg", bg);
	main->addToRenderOrder("bg");
	for (auto a: _normalDucks) {
		a->setPosition({100 + offset, 0 + distr(eng)});
		offset += 110;
		main->addSpriteToScene("normal duck" + offset, a);
		main->addToRenderOrder("normal duck" + offset);
	}
	// duck1->setPosition({100, 100});
	// duck2->setPosition({200, 200});

	// main->addSpriteToScene("duck1", duck1);
	// main->addSpriteToScene("duck2", duck2);
	// main->addToRenderOrder("duck1");
	// main->addToRenderOrder("duck2");
	return true;
}


bool DuckEngine::onUserUpdate(float elapsedTime) {
	int index;

	sf::Vector2f movement = {20, 0};
	// AnimatedSprite *duck1 = getCurrentScene()->getSprite("duck1");
	// AnimatedSprite *duck2 = getCurrentScene()->getSprite("duck2");

	for (auto a: _normalDucks) {
		a->move(movement * a->getSpeed() * elapsedTime);
		a->update(_timer.getElapsedTime());
	}
	// duck1->move(movement * duck1->getSpeed() * elapsedTime);
	// duck2->move(movement * duck2->getSpeed() * elapsedTime);
	// duck1->update(_timer.getElapsedTime());
	// duck2->update(_timer.getElapsedTime());
	return true;
}