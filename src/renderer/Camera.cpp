#include "Camera.h"

Camera::Camera(float aspect) : aspectRatio(aspect) {}

glm::mat4 Camera::view() const {
    return glm::lookAt(pos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}

glm::mat4 Camera::projection() const {
    return glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
}
