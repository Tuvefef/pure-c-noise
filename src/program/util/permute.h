#ifndef PERMUTEH
#define PERMUTEH

#include "gfunctions.h"

unsigned int permute[512];

void renderPermute(int seedInit)
{
    int pp[256];
    for(int i = 0; i < 256; i++)
        pp[i] = i;

    srand(seedInit);

    for(int i = 255; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = pp[i];
        pp[i] = pp[j];   
        pp[j] = temp;
    }

    for(int i = 0; i < 256; i++)
    {
        permute[i] = pp[i];
        permute[i + 256] = pp[i];
    }
}

float renderHash2d(int x, int y)
{
    int i = permute[(permute[x & 255] + (y & 255)) & 255];
    return (float)i / 256.0f;
}

float renderHash3d(int x, int y, int z)
{
    int i = permute[(permute[(permute[x & 255] + (y & 255)) & 255] + (z & 255)) & 255];
    return (float)i / 256.0f;
}

gvector2 unitGradient(float x, float y)
{
    float g = renderHash2d((int)x, (int)y) * PI2;
    return (gvector2){sin(g), cos(g)};
}

gvector3 unitGradient3d(float x, float y, float z)
{
    float g1 = renderHash3d((int)x, (int)y, (int)z) * PI2;
    float g2 = renderHash3d((int)x + 1, (int)y + 1, (int)z + 1) * PI2;
    return (gvector3){sin(g1) * cos(g2), sin(g1) * sin(g2), cos(g1)};
}

#endif