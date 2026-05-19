#include "Window.h"
#include <glad/gl.h>
#include "Input.h"

Window::Window(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    window=SDL_CreateWindow("Orion",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_OPENGL);
    ctx=SDL_GL_CreateContext(window);
    gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);
    SDL_GL_SetSwapInterval(1);
    Input::init();
}
Window::~Window(){ SDL_GL_DeleteContext(ctx); SDL_DestroyWindow(window); SDL_Quit(); }

void Window::pollEvents(){
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type==SDL_QUIT) running=false;
        Input::handleEvent(e);
    }
}

void Window::swap(){ SDL_GL_SwapWindow(window); }
bool Window::isRunning() const{ return running; }
