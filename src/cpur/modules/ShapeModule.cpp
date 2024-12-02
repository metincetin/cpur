#include "ShapeModule.h"

cpur::ShapeModule::ShapeModule(ShapeParams *params): params(params){
}

void cpur::ShapeModule::start(Particle &particle){
    params->start(particle);
}

void cpur::ShapeModule::update(float delta, Particle &particle){
}
