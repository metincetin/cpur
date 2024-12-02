cmake_minimum_required(VERSION 3.25)

project(cpur)

set(SRC
src/main.cpp
src/cpur/Particle.h
src/cpur/Emitter.h
src/cpur/Types.h
src/cpur/modules/GravityModule.cpp
src/cpur/modules/GravityModule.h
src/cpur/modules/ShapeModule.cpp
src/cpur/modules/ShapeModule.h
src/cpur/modules/IStarterModule.h
src/cpur/modules/shape_params/SphereShapeParams.cpp
src/cpur/modules/shape_params/SphereShapeParams.h

src/cpur/modules/InitialParticlePropertyModule.h
src/cpur/modules/InitialParticlePropertyModule.cpp

src/cpur/modules/BaseLifetimeModule.h
src/cpur/modules/SizeOverLifetimeModule.cpp
src/cpur/modules/SizeOverLifetimeModule.h
)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

# add_library(cpur STATIC ${SRC})

add_executable(cpur ${SRC})

target_link_libraries(cpur PUBLIC glm)
