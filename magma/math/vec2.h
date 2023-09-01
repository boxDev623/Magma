#pragma once

#include "base.h"

typedef union mg_vec2
{
    struct
    {
        float x;
        float y;
    };
    struct
    {
        float r;
        float g;
    };
    float v[2];
}
mg_vec2_t;