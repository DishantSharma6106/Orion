#include "Components.h"
#include <entt/entt.hpp>
void movementSystem(entt::registry& r,float dt){
    auto v=r.view<Transform,Velocity>();
    for(auto e:v){ auto& t=v.get<Transform>(e); auto& vel=v.get<Velocity>(e); t.position+=vel.value*dt; }
}
