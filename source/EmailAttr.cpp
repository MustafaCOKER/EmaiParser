#include <iostream>

#include "EmailAttr.hpp"
#include "ItemParser.hpp"

EmailAttr::EmailAttr(string key) : _key(key), _parser(PARSERS::InitialParser)
{/* Deliberately Empty */}

EmailAttr::EmailAttr(string key, ParserFunctionType parser) 
    : _key(key), _parser(parser) 
{/* Deliberately Empty */}

string EmailAttr::GetKey() const
{ return _key; }

BeginEndOffsets EmailAttr::GetOffsets() const
{ return _begin_end_offsets; }

void EmailAttr::SetVal(BeginEndOffsets item)
{ _begin_end_offsets = item; }