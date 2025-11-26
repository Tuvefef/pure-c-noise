#ifndef PERMUTEH
#define PERMUTEH

#include "gfunctions.hpp"

extern unsigned int permute[512];

void renderPermute(int seedInit);
float renderHash2d(int x, int y);
float renderHash3d(int x, int y, int z);
gvector2 unitGradient(float x, float y);
gvector3 unitGradient3d(float x, float y, float z);

#endif