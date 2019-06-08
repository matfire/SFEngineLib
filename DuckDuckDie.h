#pragma once


#include "Engine.h"
#include "assetManager.h"
#include "AnimatedSprite.hpp"


class DuckEngine: public Engine {
	public:
		DuckEngine();
		~DuckEngine();
		bool onUserUpdate(float elapsedTime) override;
		bool onUserCreate() override;
	private:
		int _level;
		std::list<Sprite *> _normalDucks;
		std::list<Sprite *> _hardDucks;
		sf::Text _score;
		sf::Font _font;

};

class NormalDuck: public Sprite {
	public:
		NormalDuck() : Sprite("normal duck") {
			_speed = 5;
			setInterval(sf::seconds(0.2));
			_flyingAnimation.setSpriteSheet(*assetManager::get().getTexture("normal duck"));
			_flyingAnimation.addFrame(sf::IntRect(0, 0, 110, 110));
			_flyingAnimation.addFrame(sf::IntRect(110, 0, 110, 110));
			_flyingAnimation.addFrame(sf::IntRect(220, 0, 110, 110));
			setAnimation(_flyingAnimation);
		};
		~NormalDuck(){};
	private:
	Animation _flyingAnimation;

};

class HardDuck: public Sprite {
	public:
		HardDuck(): Sprite("hard duck") {
			_speed = 8;
			setInterval(sf::seconds(0.1));
			_flyingAnimation.setSpriteSheet(*assetManager::get().getTexture("hard duck"));
			_flyingAnimation.addFrame(sf::IntRect(0, 0, 110, 110));
			_flyingAnimation.addFrame(sf::IntRect(110, 0, 110, 110));
			_flyingAnimation.addFrame(sf::IntRect(220, 0, 110, 110));
			setAnimation(_flyingAnimation);
		};
		~HardDuck(){};
	private:
		Animation _flyingAnimation;
};