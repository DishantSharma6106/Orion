cmake_minimum_required(VERSION 3.20)
project(Orion LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/SDL2)
add_subdirectory(external/glad)

add_executable(Orion
    src/main.cpp
    src/core/Application.cpp
    src/core/Window.cpp
    src/core/Time.cpp
    src/renderer/Renderer.cpp
    src/renderer/Camera.cpp
    src/ecs/Systems.cpp
    src/game/Game.cpp
    src/game/PlayerSystem.cpp
    src/game/EnemySystem.cpp
)

target_include_directories(Orion PRIVATE
    src
    external/glm
    external/imgui
    external/entt/src
    external/glad/include
    external/SDL2/include
)

target_link_libraries(Orion PRIVATE SDL2 glad)
