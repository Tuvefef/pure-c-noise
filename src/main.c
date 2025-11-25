#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "program/core/gnoise.h"
#include "program/core/config.h"

int main(void)
{
    renderPermute(42);
    FILE *f = fopen("perlin_noise.pgm", "w");
    if(!f)
    {
        perror("fopen");
        return 1;
    }

    fprintf(f, "P2\n256 256\n255\n");
    for(int y = 0; y < 256; y++)
    {
        for(int x = 0; x < 256; x++)
        {
            #if defined(PERLIN2) || (!defined(PERLIN2) && !defined(PERLIN3))
            gvector2 texcoord = {x * SCALE, y * SCALE};
            float noiseValue = computePerlinNoise2d(texcoord);
            #elif defined(PERLIN3)
            gvector3 texcoord3 = {x * SCALE, y * SCALE, 10.0};
            float noiseValue = computePerlinNoise3d(texcoord3);
            #endif

            int val = (int)((noiseValue + 1.0f) * 0.5f * 255.0f);
            if(val < 0) val = 0;
            if(val > 255) val = 255;
            fprintf(f, "%d ", val);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    printf("perlin_noise.pgm generates!\n");
}
