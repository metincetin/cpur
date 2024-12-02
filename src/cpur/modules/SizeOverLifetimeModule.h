#ifndef SIZEOVERLIFETIMEMODULE_H
#define SIZEOVERLIFETIMEMODULE_H

#include "BaseLifetimeModule.h"

namespace cpur {

class SizeOverLifetimeModule: public BaseLifetimeModule<glm::vec3>
{
public:
    SizeOverLifetimeModule(std::function<glm::vec3(float)> function) : BaseLifetimeModule(function) {}
    void update(float delta, Particle &particle) override;
};
}

#endif // SIZEOVERLIFETIMEMODULE_H
