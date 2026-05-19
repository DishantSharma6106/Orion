#pragma once
#include <entt/entt.hpp>
class Game{
public:
    Game(); void update(float);
    const entt::registry& getRegistry() const { return registry; }
private:
    entt::registry registry;
};
