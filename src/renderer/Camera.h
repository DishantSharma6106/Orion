#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    glm::mat4 view() const;

private:
    glm::vec3 pos{0, 0, 5};
};
