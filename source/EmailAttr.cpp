#include <iostream>

#include "EmailAttr.hpp"
#include "ItemParser.hpp"

EmailAttr::EmailAttr(string key)
    : _key(key), _parser(PARSERS::InitialParser), _isFound(false)
{/* Deliberately Empty */}

EmailAttr::EmailAttr(string key, ParserFunctionType parser, bool isMultiple) 
    : _key(key), _parser(parser), _isMultiple(isMultiple), _isFound(false)
{/* Deliberately Empty */}

string EmailAttr::GetKey() const
{ return _key; }

BeginEndOffsets EmailAttr::GetOffsets() const
{ return _begin_end_offsets; }

bool EmailAttr::isMultiple() const
{ return _isMultiple; }

void EmailAttr::setFound()
{ _isFound = true; }

bool EmailAttr::isFound() const
{ return _isFound; }

void EmailAttr::SetVal(BeginEndOffsets item)
{ _begin_end_offsets = item; }