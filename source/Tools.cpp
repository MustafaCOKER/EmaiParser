#include "Tools.hpp"

uint32_t Util::GotoEndofLine(const char *content)
{
    uint32_t ret = 0;

    do { ++ret; ++content; } while( *content != '\0' && Util::not_in<char>(*content, {'\n', '\r'}));

    while(*content != '\0' && Util::in<char>(*content, {'\n', '\r'})) { ++ret; ++content; }

    return ret;
}