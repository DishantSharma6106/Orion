#include <entt/entt.hpp>
#include "../ecs/Components.h"
#include "../core/Input.h"

void playerSystem(entt::registry& r, float dt) {
    auto view = r.view<Transform, Velocity, PlayerController>();
    for (auto e : view) {
        auto& transform = view.get<Transform>(e);
        auto& velocity = view.get<Velocity>(e);
        auto& controller = view.get<PlayerController>(e);

        // Horizontal movement
        velocity.value.x = 0;
        if (Input::isKeyPressed(SDL_SCANCODE_A)) {
            velocity.value.x = -controller.moveSpeed;
        }
        if (Input::isKeyPressed(SDL_SCANCODE_D)) {
            velocity.value.x = controller.moveSpeed;
        }

        // Jumping
        if (Input::isKeyPressed(SDL_SCANCODE_SPACE) && controller.grounded) {
            velocity.value.y = controller.jumpForce;
            controller.grounded = false;
        }

        // Gravity
        if (!controller.grounded) {
            velocity.value.y -= 20.0f * dt; // Gravity constant
        }

        // Apply velocity to transform
        transform.position += velocity.value * dt;

        // Ground Collision (Floor at Y = 0)
        if (transform.position.y <= 0.0f) {
            transform.position.y = 0.0f;
            velocity.value.y = 0.0f;
            controller.grounded = true;
        }
    }
}
