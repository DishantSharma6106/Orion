#include "Game.h"
#include "../ecs/Components.h"
Game::Game(){
    auto p=registry.create();
    registry.emplace<Transform>(p,glm::vec2{0,0});
    registry.emplace<Velocity>(p,glm::vec2{1,0});
}
void Game::update(float){}
