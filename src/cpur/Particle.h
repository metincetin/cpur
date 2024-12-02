#ifndef PARTICLE_H
#define PARTICLE_H
#include "Types.h"
#include "glm/ext/matrix_float4x4.hpp"

namespace cpur{
struct Particle{
    float lifetime;
    float maxLifetime;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale = {1,1,1};
    glm::vec3 velocity;
    color vertexColor;

    bool isAlive = false;
    bool positionDirty = true;
    bool rotationDirty = true;
    bool scaleDirty = true;

    glm::mat4 translationMatrix;
    glm::mat4 rotationMatrix;
    glm::mat4 scaleMatrix;

    float getLife(){
        return 1 - lifetime / maxLifetime;
    }

    Particle(){}
    Particle(float lifetime) : lifetime(lifetime){
        maxLifetime = lifetime;
        position[0] = 0;
        position[1] = 0;
        position[2] = 0;

        velocity[0] = 0;
        velocity[1] = 0;
        velocity[2] = 0;
        isAlive = false;
    }
};
};
#endif
