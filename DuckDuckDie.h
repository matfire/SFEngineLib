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
		std::list<AnimatedSprite *> _normalDucks;
		std::list<AnimatedSprite *> _hardDucks;

};

class NormalDuck: public AnimatedSprite {
	public:
		NormalDuck() : AnimatedSprite(sf::seconds(0.2), false, true) {
			_speed = 5;
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

class HardDuck: public AnimatedSprite {
	public:
		HardDuck(): AnimatedSprite(sf::seconds(0.1), false, true) {
			_speed = 8;
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