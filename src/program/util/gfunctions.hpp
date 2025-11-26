#ifndef GLSL_FUNCTIONSH
#define GLSL_FUNCTIONSH

#include <cmath>

#define POWX2(a) ((a) * (a))
#define POWX3(a) (POWX2(a) * (a))
#define PI2 6.2831853f

#define GMIX(a, b, t) ((a) + (t) * ((b) - (a)))
#define GSMOOTH(a) (POWX2(a) * (3.0 - 2.0 * (a)))

constexpr double gpowx2(double g)
{
    return g * g;
}

constexpr double gpowx3(double g1)
{
    double g2 = gpowx2(g1);
    return g2 * g1;
}

float gfract(float x);
float gfade(float g);

struct gvector2 
{
    float x;
    float y;
};

struct gvector3
{
    float x;
    float y;
    float z;
};

float gdot2d(gvector2 a, gvector2 b);
float gdot3d(gvector3 a, gvector3 b);

#endif