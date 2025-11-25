#ifndef PERLIN_NOISE_H
#define PERLIN_NOISE_H

#include "../util/gfunctions.h"
#include "../util/permute.h"

float computePerlinNoise2d(gvector2 texcoord)
{
    gvector2 gi;
    gi.x = floor(texcoord.x);
    gi.y = floor(texcoord.y);
    gvector2 gg;
    gg.x = gfract(texcoord.x);
    gg.y = gfract(texcoord.y);

    gvector2 g00 = unitGradient(gi.x, gi.y);
    gvector2 g10 = unitGradient(gi.x + 1, gi.y);
    gvector2 g01 = unitGradient(gi.x, gi.y + 1);
    gvector2 g11 = unitGradient(gi.x + 1, gi.y + 1);
    
    gvector2 d00 = (gvector2){gg.x, gg.y};
    gvector2 d10 = (gvector2){gg.x - 1, gg.y};
    gvector2 d01 = (gvector2){gg.x, gg.y - 1};
    gvector2 d11 = (gvector2){gg.x - 1, gg.y - 1};

    float v00 = gdot2d(g00, d00);
    float v10 = gdot2d(g10, d10);
    float v01 = gdot2d(g01, d01);
    float v11 = gdot2d(g11, d11);

    gvector2 uu;
    uu.x = gfade(gg.x);
    uu.y = gfade(gg.y);
    return GMIX(GMIX(v00, v10, uu.x), GMIX(v01, v11, uu.x), uu.y);
}

float computePerlinNoise3d(gvector3 texcoord)
{
    gvector3 gi;
    gi.x = floor(texcoord.x);
    gi.y = floor(texcoord.y);
    gi.z = floor(texcoord.z);
    gvector3 gg;
    gg.x = gfract(texcoord.x);
    gg.y = gfract(texcoord.y);
    gg.z = gfract(texcoord.z);

    gvector3 g000 = unitGradient3d(gi.x, gi.y, gi.z);
    gvector3 g100 = unitGradient3d(gi.x + 1, gi.y, gi.z);
    gvector3 g010 = unitGradient3d(gi.x, gi.y + 1, gi.z);
    gvector3 g110 = unitGradient3d(gi.x + 1, gi.y + 1, gi.z);
    gvector3 g001 = unitGradient3d(gi.x, gi.y, gi.z + 1);
    gvector3 g101 = unitGradient3d(gi.x + 1, gi.y, gi.z + 1);
    gvector3 g011 = unitGradient3d(gi.x, gi.y + 1, gi.z + 1);
    gvector3 g111 = unitGradient3d(gi.x + 1, gi.y + 1, gi.z + 1);

    gvector3 d000 = (gvector3){gg.x, gg.y, gg.z};
    gvector3 d100 = (gvector3){gg.x - 1, gg.y, gg.z};
    gvector3 d010 = (gvector3){gg.x, gg.y - 1, gg.z};
    gvector3 d110 = (gvector3){gg.x - 1, gg.y - 1, gg.z};
    gvector3 d001 = (gvector3){gg.x, gg.y, gg.z - 1};
    gvector3 d101 = (gvector3){gg.x - 1, gg.y, gg.z - 1};
    gvector3 d011 = (gvector3){gg.x, gg.y - 1, gg.z - 1};
    gvector3 d111 = (gvector3){gg.x - 1, gg.y - 1, gg.z - 1};

    float n000 = gdot3d(g000, d000);
    float n100 = gdot3d(g100, d100);
    float n010 = gdot3d(g010, d010);
    float n110 = gdot3d(g110, d110);
    float n001 = gdot3d(g001, d001);
    float n101 = gdot3d(g101, d101);
    float n011 = gdot3d(g011, d011);
    float n111 = gdot3d(g111, d111);

    gvector3 uu;
    uu.x = gfade(gg.x);
    uu.y = gfade(gg.y);
    uu.z = gfade(gg.z);

    float x00 = GMIX(n000, n100, uu.x);
    float x10 = GMIX(n010, n110, uu.x);
    float x01 = GMIX(n001, n101, uu.x);
    float x11 = GMIX(n011, n111, uu.x);

    return GMIX(GMIX(x00, x10, uu.y), GMIX(x01, x11, uu.y), uu.z);
}

#endif