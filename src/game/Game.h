#pragma once
#include <entt/entt.hpp>
class Game{
public:
    Game(); void update(float);
private:
    entt::registry registry;
};
