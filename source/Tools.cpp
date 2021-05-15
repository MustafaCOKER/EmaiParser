#include "Tools.hpp"
#include <iostream>

uint32_t Util::GotoEndofLine(const char *content)
{
    uint32_t ret = 0;

    do { ++ret; ++content; } while( *content != '\0' && Util::not_in<char>(*content, {'\n', '\r'}));

    while(*content != '\0' && Util::in<char>(*content, {'\n', '\r'})) { ++ret; ++content; }

    return ret;
}

uint32_t Util::strnchr(const char *str, char c, uint32_t len)
{
    uint32_t res = 0;
    bool found = false;

    while(*(str+res) != '\0' && res != len) 
    {
        if (*(str+res) == c)
            return res;

        ++res;
    }

    return len+1;
}

uint32_t Util::CleanWhiteSpaces(const char *str, uint32_t endofline)
{
    while (*(str+endofline) != '\0' && ( *(str+endofline) == '\r' || *(str+endofline) == '\n') ) 
    { --endofline; }

    return endofline;
}