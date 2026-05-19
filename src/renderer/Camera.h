#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(float aspect);

    glm::mat4 view() const;
    glm::mat4 projection() const;

private:
    glm::vec3 pos{0, 2, 5};
    float aspectRatio;
};
