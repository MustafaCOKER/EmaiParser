#include <utility>
#include <iostream>
#include <string>
#include <cstring>

#include "Defs.hpp"
#include "Tools.hpp"
#include "ItemParser.hpp"
#include "EmailAttr.hpp"

uint32_t PARSERS::InitialParser(const char *, EmailAttr& attr, uint32_t endofline)
{
    std::cerr << "Please Set Parser for " << attr.GetKey() << std::endl; 
    return attr.GetKey().size(); 
}

uint32_t PARSERS::OneLineAttrParser(const char *content, EmailAttr& attr, uint32_t endofline)
{
    const uint32_t keysize = attr.GetKey().size(); 

    attr.SetVal(std::make_pair(content+keysize, endofline-keysize));

    BeginEndOffsets be = attr.GetOffsets();
    std::string ss(be.first, be.second);
    // std::cout << "Key : [" << attr.GetKey() << "] Value Str : [" << ss << "]\n";

    return endofline;
}

uint32_t PARSERS::ReferenceParser(const char *content, EmailAttr& attr, uint32_t endofline)
{
    const uint32_t keysize = attr.GetKey().size(); 
    
    while(*(content + endofline) == '\t')
        endofline += Util::GotoEndofLine(content+endofline);
    
    attr.SetVal(std::make_pair(content+keysize, endofline-keysize));
    BeginEndOffsets be = attr.GetOffsets();
    std::string ss(be.first, be.second);
    // std::cout << "Key : [" << attr.GetKey() << "] Value Str : [" << ss << "]\n";

    return endofline;
}
 
uint32_t PARSERS::ContentAttrParser(const char *content, EmailAttr& attr, uint32_t endofline)
{
    const uint32_t keysize = attr.GetKey().size();
    const char *curr = content; 
    const char boundary_key[] = "boundary=\"";
    char boundary[MAX_BOUNDARY_SIZE] = {0};

    curr += keysize;
    ++curr; // for space between content type and next keyword

    uint32_t boundary_index = Util::strnchr(content+keysize+1, ' ', endofline-keysize-1);
    

    curr += boundary_index;
    ++curr; // skip space before boundary

    if (std::strncmp(curr, boundary_key, std::strlen(boundary_key) ) != 0)
    {
        
    }

    std::string boundary_(curr, endofline - (curr-content));
    std::cerr << "boundary : [" << boundary_ << "]\n";

    return endofline;
}