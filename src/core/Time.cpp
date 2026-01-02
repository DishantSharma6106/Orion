#include "Time.h"
void Time::update(){ auto now=clock::now(); if(last.time_since_epoch().count()) dt=std::chrono::duration<float>(now-last).count(); last=now; }
float Time::delta() const{ return dt; }
