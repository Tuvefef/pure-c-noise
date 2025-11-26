#include <iostream>
#include <cstdlib>
#include <fstream>

#include "program/core/gnoise.hpp"
#include "program/core/config.hpp"

int main(void)
{
    renderPermute(42);
    std::ofstream ff("noise.pgm");
    ff << "P2\n256 256\n255\n";
    for(int y = 0; y < 256; y++)
    {
        for(int x = 0; x < 256; x++)
        {
            gvector2 rendercoord2 = {x * SCALE, y * SCALE};
            gvector3 rendercoord3 = {x * SCALE, y * SCALE, zslice};
            PerlinNoise2d per2(rendercoord2);
            PerlinNoise3d per3(rendercoord3);

            float valnoise = per3.fractBrwnMot();
            int val = static_cast<int>((valnoise + 1.0f) * 0.5f * 255.0f);
            ff << val << " ";
        }
    }
}
