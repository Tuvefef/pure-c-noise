#include "program/core/gnoise.hpp"
#include "program/core/config.hpp"

PerlinNoise2d::PerlinNoise2d(gvector2 &coord) :
    datacoord(coord)
{}
PerlinNoise3d::PerlinNoise3d(gvector3 &coord) :
    datacoord(coord)
{}

float PerlinNoise2d::computeNoise()
{
    gvector2 gi;
    gi.x = floor(datacoord.x);
    gi.y = floor(datacoord.y);
    gvector2 gg;
    gg.x = gfract(datacoord.x);
    gg.y = gfract(datacoord.y);

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

float PerlinNoise3d::computeNoise()
{
    gvector3 gi;
    gi.x = floor(datacoord.x);
    gi.y = floor(datacoord.y);
    gi.z = floor(datacoord.z);
    gvector3 gg;
    gg.x = gfract(datacoord.x);
    gg.y = gfract(datacoord.y);
    gg.z = gfract(datacoord.z);

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

float PerlinNoise2d::fractBrwnMot()
{
    float g = exp2(-1.0);
    float f = 1.0;
    float a = 1.0;
    float t = 0.0;
    for(int i = 0; i < octaves; i++)
    {
        gvector2 coord {datacoord.x * f, datacoord.y * f};
        PerlinNoise2d pn(coord);
        t += pn.computeNoise() * a;
        f *= 2.0;
        a *= g;
    }
    return t;
}

float PerlinNoise3d::fractBrwnMot()
{
    float g = exp2(-1.0);
    float f = 1.0;
    float a = 1.0;
    float t = 0.0;
    for(int i = 0; i < octaves; i++)
    {
        gvector3 coord {datacoord.x * f, datacoord.y * f, datacoord.z * f};
        PerlinNoise3d pn(coord);
        t += pn.computeNoise() * a;
        f *= 2.0;
        a *= g;
    }
    return t;
}