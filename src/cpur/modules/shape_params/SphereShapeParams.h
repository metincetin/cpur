#ifndef SPHERESHAPEPARAMS_H
#define SPHERESHAPEPARAMS_H

#include "../../Particle.h"
#include "../ShapeParams.h"
#include <cstdlib>

namespace cpur {

class SphereShapeParams : public ShapeParams {
public:
  float radius;

  SphereShapeParams(float radius);

  void start(Particle &particle) override;
};
} // namespace cpur
#endif
