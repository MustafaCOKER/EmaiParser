#pragma once

#include <cstdint>
#include <string>

#include <initializer_list>

class Util
{
    public:
        Util() = delete;
        ~Util() = delete;

        static std::string uchar2hex(unsigned char inchar);

        template<typename T>
        static bool in(T val, std::initializer_list<T> valList );

        template<typename T>
        static bool not_in(T val, std::initializer_list<T> valList );

        static uint32_t GotoEndofLine(const char *content);
        static uint32_t strnchr(const char *str, char c, uint32_t len);

        static uint32_t CleanWhiteSpaces(const char *, uint32_t);
};

template<typename T>
bool Util::in(T val, std::initializer_list<T> valList )
{
    for (auto item : valList)
        if ( item == val)
            return true;

    return false;
}

template<typename T>
bool Util::not_in(T val, std::initializer_list<T> valList )
{
    for (auto item : valList)
        if ( item == val)
            return false;

    return true;
}
