#ifndef FALLINGSAND_PARTICLE_H
#define FALLINGSAND_PARTICLE_H

#include <vector>
using namespace std;

enum element {AIR = 15, WATER = 9, SAND = 14, STEAM = 8};

class Particle {
protected:
    element id = AIR;
public:
    Particle();
    explicit Particle(element elem);

    element getId() const { return id; };

    virtual Particle *&find(vector<Particle *> &map, int i, int j, int width, int height);
};

class Water: public Particle {
public:
    Water();
    Particle *&find(vector<Particle *> &map, int i, int j, int width, int height) override;
};

class ParticleMap {
private:
    vector<Particle *>map;
    int particles = 0;
    int width, height, dimension;
public:
    ParticleMap();
    ParticleMap(int _width, int _height);
    ~ParticleMap();

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    Particle *& get(int i, int j);

    int updateCnt();
    void update(int i, int j);
};

#endif //FALLINGSAND_PARTICLE_H
