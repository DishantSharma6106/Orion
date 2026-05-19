#pragma once

#include <SDL.h>
#include <unordered_map>

class Input {
public:
    static void init();
    static void update();
    static bool isKeyPressed(SDL_Scancode key);

    // Call this from Window::pollEvents
    static void handleEvent(const SDL_Event& e);

private:
    static std::unordered_map<SDL_Scancode, bool> keys;
};
