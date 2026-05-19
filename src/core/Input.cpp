#include "Input.h"

std::unordered_map<SDL_Scancode, bool> Input::keys;

void Input::init() {}

void Input::update() {
    // Current frame update if needed
}

void Input::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        keys[e.key.keysym.scancode] = true;
    } else if (e.type == SDL_KEYUP) {
        keys[e.key.keysym.scancode] = false;
    }
}

bool Input::isKeyPressed(SDL_Scancode key) {
    return keys[key];
}
