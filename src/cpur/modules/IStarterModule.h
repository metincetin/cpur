#ifndef ISTARTERMODULE_H
#define ISTARTERMODULE_H


namespace cpur{

class Particle;

class IStarterModule{
public:
    virtual void start(Particle &particle) = 0;
};
}

#endif
