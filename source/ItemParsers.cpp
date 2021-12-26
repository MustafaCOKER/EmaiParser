#include <utility>
#include <iostream>
#include <string>
#include <cstring>

#include "Defs.hpp"
#include "Tools.hpp"
#include "ItemParser.hpp"
#include "EmailAttr.hpp"

uint32_t PARSERS::InitialParser(const char *, EmailAttr &attr, uint32_t endofline)
{
    std::cerr << "Please Set Parser for " << attr.GetKey() << std::endl;
    return attr.GetKey().size();
}

uint32_t PARSERS::OneLineAttrParser(const char *content, EmailAttr &attr, uint32_t endofline)
{
    const uint32_t keysize = attr.GetKey().size();

    attr.SetVal(std::make_pair(content + keysize, endofline - keysize));

    BeginEndOffsets be = attr.GetOffsets();
    std::string ss(be.first, be.second - 2);
    // std::cout << "Key : [" << attr.GetKey() << "] Value Str : [" << ss << "]\n";

    return endofline;
}

uint32_t PARSERS::ReferenceParser(const char *content, EmailAttr &attr, uint32_t endofline)
{
    const uint32_t keysize = attr.GetKey().size();
    uint32_t curr = endofline;
    bool inParsing = false;

    while (*(content + curr) != '\0')
    {
        if (!IS_WSPACE(*(content + curr)))
            if (!inParsing)
                if (*(content + curr) == '<')
                    inParsing = true;
                else
                    break;

            else if (*(content + curr) == '>')
                inParsing = false;

        ++curr;
    }

    attr.SetVal(std::make_pair(content + keysize, curr - keysize));
    BeginEndOffsets be = attr.GetOffsets();
    std::string ss(be.first, be.second);
    // std::cout << "Key : [" << attr.GetKey() << "] Value Str : [" << ss << "]\n";

    return curr;
}

uint32_t PARSERS::ContentAttrParser(const char *content, EmailAttr &attr, uint32_t endofline)
{
    const uint32_t keysize = attr.GetKey().size();
    const char *curr = content + keysize;
    constexpr char boundary_key[] = "boundary=\"";
    char boundary[MAX_BOUNDARY_SIZE] = {0};

    return endofline;
}