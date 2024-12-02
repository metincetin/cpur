
#include "cpur/Emitter.h"
#include "cpur/Types.h"
#include "cpur/modules/GravityModule.h"
#include "cpur/modules/InitialParticlePropertyModule.h"
#include "cpur/modules/ShapeModule.h"
#include "cpur/modules/SizeOverLifetimeModule.h"
#include "cpur/modules/shape_params/SphereShapeParams.h"
#include <cstdio>
#include <cstdlib>
#include <thread>

glm::vec3 getScale(float lifetime){
    float v = 5.f;
    return glm::vec3(v,v,v);
}

int main(){
    std::srand(std::time(0));
    auto builder = cpur::Emitter<100>::Builder::create();

    cpur::Emitter<100> emitter = builder
        .withDuration(1)
        .withRate(0.2f)
        .withLifeTime(4)
        .addModule(new cpur::GravityModule())
        .addModule(new cpur::ShapeModule(new cpur::SphereShapeParams(0.5f)))
        .addModule(new cpur::InitialParticlePropertyModule(cpur::E_VertexColor, new float[4] {1.0f, 0.0f, 0.0f, 1.0f}))
        .addModule(new cpur::SizeOverLifetimeModule(getScale))
        .build();


    while(true){
        emitter.update(0.016f);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }


    return 0;
}
