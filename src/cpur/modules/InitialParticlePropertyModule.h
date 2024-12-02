#ifndef INITIALPARTICLEPROPERTYMODULE_H
#define INITIALPARTICLEPROPERTYMODULE_H

#include "IStarterModule.h"
#include "../Module.h"

namespace cpur{

class InitialParticlePropertyModule: public Module, public IStarterModule
{
public:
    InitialParticlePropertyModule(PropertyType type, void* valuePtr) {
        propertyType = type;
        this->valuePtr = valuePtr;
    }

public:
    void start(Particle &particle);
    void update(float delta, Particle &particle);

private:
    PropertyType propertyType;
    void* valuePtr;
};

}

#endif // INITIALPARTICLEPROPERTYMODULE_H
