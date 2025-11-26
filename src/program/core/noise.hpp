#ifndef NOISECLASSH
#define NOISECLASSH

#include "../util/gfunctions.hpp"
#include "../util/permute.hpp"

class Noise
{
    public:
        virtual float computeNoise() = 0;
        virtual float fractBrwnMot() = 0;
        virtual ~Noise() = default; 
};

#endif