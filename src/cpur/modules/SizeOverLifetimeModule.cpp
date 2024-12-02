#include "SizeOverLifetimeModule.h"

void cpur::SizeOverLifetimeModule::update(float delta, Particle &particle) {
    particle.scale = getValue(particle.lifetime);
}
