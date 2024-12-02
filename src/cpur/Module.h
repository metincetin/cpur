#ifndef MODULE_H
#define MODULE_H

#include "Particle.h"

namespace cpur{
class Module{
    public:
    virtual void update(float delta, Particle& particle) = 0;
};
}

#endif
