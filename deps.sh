#!/bin/bash
mkdir -p external && cd external
git clone -b release-2.30.0 https://github.com/libsdl-org/SDL.git SDL2
git clone -b 1.0.0 https://github.com/g-truc/glm.git glm
git clone -b v1.91.5 https://github.com/ocornut/imgui.git imgui
git clone -b v3.13.2 https://github.com/skypjack/entt.git entt
git clone https://github.com/Dav1dde/glad.git glad
cd glad
python3 -m pip install jinja2
python3 -m glad --api gl:core=3.3 --out-path=./ c
echo 'add_library(glad src/gl.c)
target_include_directories(glad PUBLIC include)' > CMakeLists.txt
