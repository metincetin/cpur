#include "GravityModule.h"
#include <cstdio>

void cpur::GravityModule::update(float delta, Particle& particle){
    particle.velocity[1] += GravityConstant * delta;
}
