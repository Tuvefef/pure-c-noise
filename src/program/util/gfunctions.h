#ifndef GLSL_FUNCTIONSH
#define GLSL_FUNCTIONSH

#include <math.h>

#define POWX2(a) ((a) * (a))
#define POWX3(a) (POWX2(a) * (a))
#define PI2 6.2831853f

#define GMIX(a, b, t) ((a) + (t) * ((b) - (a)))
#define GSMOOTH(a) (POWX2(a) * (3.0 - 2.0 * (a)))

float gfract(float x)
{
    return x - floor(x);
}

float gfade(float g)
{
    return POWX3(g) * (g * (g * 6.0f - 15.0f) + 10.0f);
}

typedef struct 
{
    float x;
    float y;
} gvector2;

typedef struct 
{
    float x;
    float y;
    float z;
} gvector3;

float gdot2d(gvector2 a, gvector2 b)
{
    return a.x * b.x + a.y * b.y;
}

float gdot3d(gvector3 a, gvector3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

#endif