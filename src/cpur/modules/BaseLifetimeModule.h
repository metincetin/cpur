#ifndef BASELIFETIMEMODULE_H
#define BASELIFETIMEMODULE_H

#include "../Module.h"
#include <functional>

namespace cpur{

template<typename TValue>
class BaseLifetimeModule: public Module
{
public:
    BaseLifetimeModule(std::function<TValue(float)> function) { this->function = function; }

protected:
    TValue getValue(float lifetime) const { return function(lifetime); }
private:
    std::function<TValue(float)> function;
};
}

#endif // BASELIFETIMEMODULE_H
