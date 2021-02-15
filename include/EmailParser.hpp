#pragma once

#include <string>
#include <functional>
#include <deque>

#include "EmailAttr.hpp"

using std::function;
using std::string;
using EmailAttrQueue = std::deque<EmailAttr>;

// This enum specifies index of attributes in dequeue(deque)
enum class AttributesIndex : uint32_t {
    MessageID,
    InReplyTo,
    Reference,
    From,
    To,
    Cc,
    Bcc,
    Subject,
    ContentBody_plain
};
 
//This union help us to convert enum 
// class(strongly typed) to integer in a implicit way
union AttributeIndexUnion 
{
    AttributesIndex index;
    uint32_t i_index;

    AttributeIndexUnion( AttributesIndex i ) : index(i) {}

};

class EmailParser {
public:
    EmailParser();

    EmailAttr GetAttr(AttributeIndexUnion u_index);

    bool parse(const char *email);

private:
    void PrepareAttributesQueue();
    EmailAttrQueue _attributes;
};