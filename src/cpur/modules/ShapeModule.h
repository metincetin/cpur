#ifndef SHAPEMODULE_H
#define SHAPEMODULE_H

#include "../Module.h"
#include "IStarterModule.h"
#include "ShapeParams.h"
#include <cstdlib>
#include <ctime>

namespace cpur{
    class ShapeModule: public Module, public IStarterModule{

        public:
        ShapeModule(ShapeParams* params);

        void start(Particle &particle) override;
        void update(float delta, Particle &particle) override;

        private:
        ShapeParams* params;
    };
}
#endif
