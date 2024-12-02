#ifndef EMITTER_H
#define EMITTER_H

#include "Module.h"
#include "Particle.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "modules/IStarterModule.h"
#include <cstddef>
#include <cstdio>
#include <vector>

namespace cpur {
template <size_t Capacity> class Emitter {
  typedef Particle particle_buffer[Capacity];
  typedef glm::mat4 transform_buffer[Capacity];

public:
  transform_buffer transformBuffer;
  particle_buffer particleBuffer;

  void update(float delta) {
    time += delta;

    if (time > rate) {
      time = 0;

      Particle &particle = particleBuffer[availableParticleIndex];
      particle.lifetime = lifetime;
      particle.maxLifetime = lifetime;
      particle.isAlive = true;

      availableParticleIndex++;

      for (Module *module : modules) {
        if (IStarterModule *starter = dynamic_cast<IStarterModule *>(module)) {
          starter->start(particle);
        }
      }
    }

    for (size_t i = 0; i < Capacity; ++i) {
      Particle &particle = particleBuffer[i];

      if (!particle.isAlive) {
        availableParticleIndex = i;
        continue;
      }

      particle.translationMatrix =
          glm::translate(glm::mat4(1), glm::make_vec3(particle.position));

      transformBuffer[i] = particle.translationMatrix;

      particle.lifetime -= delta;

      for (Module *module : modules) {
        module->update(delta, particle);
      }

      // apply vel
      particle.position[0] += particle.velocity[0] * delta;
      particle.position[1] += particle.velocity[1] * delta;
      particle.position[2] += particle.velocity[2] * delta;

      if (particle.lifetime <= 0) {
        availableParticleIndex = i;
        particle.isAlive = false;
      }
    }

    printf("Position: (%f, %f, %f) color: (%f,%f,%f) scale: (%f, %f, %f)\n",
           particleBuffer[availableParticleIndex].position[0],    particleBuffer[availableParticleIndex].position[1],
           particleBuffer[availableParticleIndex].position[2],    particleBuffer[availableParticleIndex].vertexColor[0],
           particleBuffer[availableParticleIndex].vertexColor[1], particleBuffer[availableParticleIndex].vertexColor[2],
           particleBuffer[availableParticleIndex].scale[0],       particleBuffer[availableParticleIndex].scale[1],
           particleBuffer[availableParticleIndex].scale[2]);
  }
  std::vector<Module *> modules;

private:
  Emitter() {}
  size_t availableParticleIndex = 0;
  float time = 0;
  float rate = 0;

  float lifetime = 0;
  float duration = 0;

public:
  class Builder {
  private:
    Builder() {}
    Emitter instance;

  public:
    static Builder create() { return Builder(); }

    Builder &withDuration(float duration) {
      instance.duration = duration;
      return *this;
    }

    Builder &withRate(float rate) {
      instance.rate = rate;
      return *this;
    }

    Builder &withLifeTime(float lifeTime) {
      instance.lifetime = lifeTime;
      return *this;
    }

    Builder &addModule(Module *module) {
      instance.modules.push_back(module);
      return *this;
    }

    Emitter build() { return instance; }
  };
};
} // namespace cpur
#endif
