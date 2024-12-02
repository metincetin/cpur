#include "SphereShapeParams.h"

cpur::SphereShapeParams::SphereShapeParams(float radius) : radius(radius) {}

void cpur::SphereShapeParams::start(Particle &particle) {
  float rX = (float)std::rand() / RAND_MAX;
  float rY = (float)std::rand() / RAND_MAX;
  float rZ = (float)std::rand() / RAND_MAX;

  particle.position[0] = rX * radius;
  particle.position[1] = rY * radius;
  particle.position[2] = rZ * radius;

  particle.velocity[0] = rX * 2.0f - 1.0f;
  particle.velocity[1] = rY * 2.0f - 1.0f;
  particle.velocity[2] = rZ * 2.0f - 1.0f;
}
