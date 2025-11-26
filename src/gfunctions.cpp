#include "program/core/gnoise.hpp"

float gfract(float x)
{
    return x - floor(x);
}

float gfade(float g)
{
    return gpowx3(g) * (g * (g * 6.0f - 15.0f) + 10.0f);
}

float gdot2d(gvector2 a, gvector2 b)
{
    return a.x * b.x + a.y * b.y;
}

float gdot3d(gvector3 a, gvector3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}