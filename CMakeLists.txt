cmake_minimum_required(VERSION 3.13)
project(SFEngineLib)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(DuckDuckDie main.cpp Engine.cpp Engine.h Sprite.cpp Sprite.h Scene.cpp Scene.h main.h DuckDuckDie.cpp DuckDuckDie.h assetManager.cpp assetManager.h Animation.cpp Animation.hpp AnimatedSprite.cpp AnimatedSprite.hpp)
target_link_libraries(DuckDuckDie sfml-graphics sfml-audio)