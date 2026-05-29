#pragma once
#include <glm/glm.hpp>

struct Transform { glm::vec2 position; };
struct Velocity { glm::vec2 value; };

struct PlayerController {
    float moveSpeed = 5.0f;
    float jumpForce = 10.0f;
    bool grounded = false;
};
