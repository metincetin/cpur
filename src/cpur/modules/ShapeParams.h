#ifndef SHAPEPARAMS_H
#define SHAPEPARAMS_H
#include "../Particle.h"
namespace cpur {
class ShapeParams {
public:
  virtual void start(Particle &particle) = 0;
};
} // namespace cpur
#endif
