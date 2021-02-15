#pragma once

#include <string>
#include <functional>
#include <utility>

using std::function;
using std::string;
using BeginEndOffsets = std::pair<const char*, uint32_t>;

// forward declaration for function type due to circular dependencies
class EmailAttr;

typedef uint32_t (*ParserFunctionType)(const char *, EmailAttr& attr);

class EmailAttr {
public:
    EmailAttr() = delete;
    EmailAttr(string key);
    EmailAttr(string key, ParserFunctionType parser);

    string GetKey() const;
    BeginEndOffsets GetOffsets() const;
    void SetVal(BeginEndOffsets item);

    ParserFunctionType _parser;
private:
    string _key;
    BeginEndOffsets _begin_end_offsets;
};