#pragma once

#include <string>
#include <functional>

using std::function;
using std::string;
using BeginEndOffsets = std::pair<const char*, uint32_t>;

// forward declaration for function type due to circular dependencies
class EmailAttr;

typedef uint32_t (*ParserFunctionType)(const char *, EmailAttr&, uint32_t);

class EmailAttr {
public:
    EmailAttr() = delete;
    EmailAttr(string key);
    EmailAttr(string key, ParserFunctionType parser, bool isMultiple=false);

    string GetKey() const;
    BeginEndOffsets GetOffsets() const;
    bool isMultiple() const;

    void setFound();
    bool isFound() const;

    void SetVal(BeginEndOffsets item);

    ParserFunctionType _parser;
private:
    string _key;
    BeginEndOffsets _begin_end_offsets;
    bool _isMultiple;
    bool _isFound;
};