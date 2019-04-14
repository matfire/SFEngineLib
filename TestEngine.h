//
// Created by matteo on 12/04/19.
//

#ifndef SFENGINE_TESTENGINE_H
#define SFENGINE_TESTENGINE_H
#include "Engine.h"


class TestEngine : public Engine
{
public:
    TestEngine();
    ~TestEngine();
    bool onUserUpdate(float elapsedTime) override;
    bool onUserCreate() override;
private:
    sf::Font _font;
};


#endif //SFENGINE_TESTENGINE_H
