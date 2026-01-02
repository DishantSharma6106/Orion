#include "Application.h"
#include "renderer/Renderer.h"
#include "game/Game.h"
void Application::run(){ Renderer r; Game g; while(window.isRunning()){ time.update(); window.pollEvents(); g.update(time.delta()); r.render(g); window.swap(); } }
