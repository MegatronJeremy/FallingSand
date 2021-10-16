#include "Particle.h"

Particle::Particle() {
    id = AIR;
}

Particle::Particle(element elem) {
    id = elem;
}

Particle *&Particle::find(vector<Particle *> &map, int i, int j, int width, int height) {
    return map[i * width + j];
}

Water::Water() {
    id = WATER;
}

Particle *&Water::find(vector<Particle *> &map, int i, int j, int width, int height) {
    int k = j;
    Particle *&c = map[i * width + j];
    if (++i == height) return c;
    if(map[i * width + j][0].getId() == AIR) {
        return map[i * width + j];
    }
    while (k > 0 && j < width - 1) {
        j++;
        if (map[i * width + j][0].getId() == AIR) {
            return map[i *width + j];
        }
        k--;
        if (map[i * width + k][0].getId() == AIR) {
            return map[i * width + k];
        }
    }
    return c;
}