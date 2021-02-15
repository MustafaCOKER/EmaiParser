#pragma once

#include <EmailAttr.hpp>

namespace PARSERS
{
    uint32_t InitialParser(const char *, EmailAttr&);
    uint32_t OneLineAttrParser(const char *, EmailAttr&);
    uint32_t ContentAttrParser(const char *, EmailAttr&);
};