#include "Game.h"
#include "../ecs/Components.h"

#include "PlayerSystem.h"


Game::Game(){
    auto p=registry.create();
    registry.emplace<Transform>(p,glm::vec2{0,0});
    registry.emplace<Velocity>(p,glm::vec2{0,0});
    registry.emplace<PlayerController>(p);
}
void Game::update(float dt){
    playerSystem(registry, dt);
}
