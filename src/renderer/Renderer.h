#pragma once

#include "game/Game.h"
#include "Shader.h"
#include "Camera.h"
#include <memory>

class Renderer {
public:
    Renderer();
    ~Renderer();
    void render(const Game&);

private:
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Camera> camera;

    unsigned int VAO, VBO;
};
