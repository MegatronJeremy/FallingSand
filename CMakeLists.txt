cmake_minimum_required(VERSION 3.20)
project(FallingSand)

set(CMAKE_CXX_STANDARD 14)

add_executable(FallingSand main.cpp Particle.cpp Particle.h ParticleMap.cpp ParticleMap.h)
