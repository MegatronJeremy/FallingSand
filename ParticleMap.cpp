#include "Particle.h"

using namespace std;

ParticleMap::ParticleMap() {
    width = 32;
    height = 33;
    dimension = 32 * 32 + 3;
    for (int i = 0; i < width * height; i++) {
        map.push_back(new Particle());
    }
}

ParticleMap::ParticleMap(int _width, int _height) {
    width = _width;
    height = _height + 1;
    dimension = width * (height - 1) + 3;
    for (int i = 0; i < width * height; i++) {
        map.push_back(new Particle());
    }
}

ParticleMap::~ParticleMap() {
    for (int i = 0; i < dimension; i++) {
        delete map[i];
    }
}

Particle *&ParticleMap::get(int i, int j) {
    return map[i * width + j];
}

void ParticleMap::update(int i, int j) {
    Particle *&p = get(i, j)->find(map, i, j, getWidth(), getHeight());
    swap(p,get(i, j));
}

int ParticleMap::updateCnt() {
    particles++;
    if (particles == dimension) return 1;
    return 0;
}