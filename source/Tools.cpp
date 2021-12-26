#include "Tools.hpp"
#include <iostream>

uint32_t Util::GotoEndofLine(const char *content)
{
    uint32_t ret = 0;

    do
    {
        ++ret;
        ++content;
    } while (*content != '\0' && Util::not_in<char>(*content, {'\n', '\r'}));

    while (*content != '\0' && Util::in<char>(*content, {'\n', '\r'}))
    {
        ++ret;
        ++content;
    }

    return ret;
}

uint32_t Util::strnchr(const char *str, char c, uint32_t len)
{
    uint32_t res = 0;
    bool found = false;

    while (*(str + res) != '\0' && res != len)
    {
        if (*(str + res) == c)
            return res;

        ++res;
    }

    return len + 1;
}

const char *Util::strnstr(const char *str1, const char *str2, uint32_t max_len)
{
    const char *pos = nullptr;

    if (str1 == nullptr || str2 == nullptr || *str1 == '\0' || *str2 == '\0')
        return nullptr;

    while (true)
    {
        if (*(++str1) == '\0' || --max_len <= 0)
            return nullptr;

        if (*(str1) == *(str2))
            break;
    }

    pos = str1;

    while (true)
    {
        if (*str1 == '\0')
        {
            if (*str2 == '\0')
                return pos;
            else
                return nullptr;
        }
        else if (*str2 == '\0')
            return pos;
        else if (*str1 == *str2)
        {
            ++str1;
            ++str2;
            continue;
        }
        else
            return nullptr;
    }

    return pos;
}

uint32_t Util::CleanWhiteSpaces(const char *str, uint32_t endofline)
{
    while (*(str + endofline) != '\0' &&
           (*(str + endofline) == '\r' ||
            *(str + endofline) == '\n'))
        --endofline;

    return endofline;
}