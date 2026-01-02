#pragma once
#include <chrono>
class Time{
public:
    void update(); float delta() const;
private:
    using clock=std::chrono::high_resolution_clock;
    clock::time_point last{};
    float dt=0.f;
};
