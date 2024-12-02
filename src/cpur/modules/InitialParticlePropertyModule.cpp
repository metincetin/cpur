#include "InitialParticlePropertyModule.h"

void cpur::InitialParticlePropertyModule::start(Particle& particle){
    switch(propertyType){
    case E_Lifetime:
        particle.lifetime = *static_cast<float*>(valuePtr);
        break;
    case E_VertexColor:
        float* begin = static_cast<float*>(valuePtr);

        particle.vertexColor[0] = begin[0];
        particle.vertexColor[1] = begin[1];
        particle.vertexColor[2] = begin[2];
        particle.vertexColor[3] = begin[3];
        break;
    }
}
void cpur::InitialParticlePropertyModule::update(float delta, Particle& particle){}
