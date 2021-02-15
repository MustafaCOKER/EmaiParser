#include "Tools.hpp"

uint32_t GotoEndofLine(const char *content)
{
    uint32_t ret = 0;

    do { ++ret; ++content; } while( *content != '\0' && *content != '\n' && *content != '\r');

    if (*(content + ret) == '\n')
        ++ret;

    return ret;
}