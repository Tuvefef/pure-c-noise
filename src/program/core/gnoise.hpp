#ifndef PERLIN_NOISE_H
#define PERLIN_NOISE_H

#include "noise.hpp"

class PerlinNoise2d : public Noise
{
    private:
        gvector2 datacoord;
    public:
        float computeNoise() override;
        float fractBrwnMot() override;
        PerlinNoise2d(gvector2 &coord);
};

class PerlinNoise3d : public Noise
{
    private:
        gvector3 datacoord;
    public:
        float computeNoise() override;
        float fractBrwnMot() override;
        PerlinNoise3d(gvector3 &coord);
};

#endif