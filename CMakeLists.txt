cmake_minimum_required(VERSION 3.13)
project(SFEngineLib)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Test main.cpp Engine.cpp Engine.h Sprite.cpp Sprite.h Scene.cpp Scene.h main.h TestEngine.cpp TestEngine.h assetManager.cpp assetManager.h)
target_link_libraries(Test sfml-graphics sfml-audio)

#add_library(SFEngineLib SHARED Engine.cpp Engine.h Sprite.cpp Sprite.h Scene.cpp Scene.h)
#target_link_libraries(SFEngineLib sfml-graphics sfml-audio)
