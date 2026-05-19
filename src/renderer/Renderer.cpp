#include "Renderer.h"
#include <glad/gl.h>
void Renderer::render(const Game&){ glClearColor(0.08f,0.08f,0.12f,1); glClear(GL_COLOR_BUFFER_BIT); }
