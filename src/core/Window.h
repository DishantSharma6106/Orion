#pragma once
#include <SDL.h>
class Window{
public:
    Window(); ~Window();
    void pollEvents(); void swap();
    bool isRunning() const;
private:
    SDL_Window* window=nullptr;
    SDL_GLContext ctx{};
    bool running=true;
};
