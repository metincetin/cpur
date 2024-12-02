#ifndef GRAVITYMODULE_H
#define GRAVITYMODULE_H
#include "../Module.h"
namespace cpur{
class GravityModule : public Module{
    public:
    void update(float delta, Particle& particle) override;

    float GravityConstant = -9.8f;
};
}
#endif
