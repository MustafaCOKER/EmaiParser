#include <utility>
#include <iostream>
#include <string>

#include "Tools.hpp"
#include "ItemParser.hpp"
#include "EmailAttr.hpp"

uint32_t PARSERS::InitialParser(const char *, EmailAttr& attr)
{
    std::cerr << "Please Set Parser for " << attr.GetKey() << std::endl; 
    return attr.GetKey().size(); 
}

uint32_t PARSERS::OneLineAttrParser(const char *content, EmailAttr& attr)
{
    uint32_t endPoint = Util::GotoEndofLine(content+attr.GetKey().size());
    
    attr.SetVal(std::make_pair(content+attr.GetKey().size(), endPoint));

    BeginEndOffsets be = attr.GetOffsets();
    std::string ss(be.first, be.second);
    std::cout << "Key : " << attr.GetKey() << " Value Str : " << ss << std::endl;

    return endPoint;
}

uint32_t PARSERS::ContentAttrParser(const char *content, EmailAttr& attr)
{
    

    return 0;
}