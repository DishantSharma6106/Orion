#include "Camera.h"

Camera::Camera(float aspect) : aspectRatio(aspect) {}

void Camera::setPosition(const glm::vec3& position) {
    pos = position;
}

glm::mat4 Camera::view() const {
    return glm::lookAt(pos, pos + glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
}

glm::mat4 Camera::projection() const {
    return glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
}
