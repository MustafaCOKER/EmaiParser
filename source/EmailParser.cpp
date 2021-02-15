#include <algorithm>
#include <cstring>
#include <iostream>

#include "Tools.hpp"
#include "ItemParser.hpp"

#include "EmailParser.hpp"

EmailParser::EmailParser()
{ PrepareAttributesQueue(); }

EmailAttr EmailParser::GetAttr(AttributeIndexUnion u_index)
{
    return _attributes[u_index.i_index];
}

void EmailParser::PrepareAttributesQueue()
{
    _attributes.emplace(_attributes.end(), EmailAttr("Message-ID:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("In-Reply-To:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("References:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("From:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("To:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("Cc:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("Subject:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), "Content-Type: ");
}

bool EmailParser::parse(const char *emailContent)
{
    uint32_t currPos = 0;

    while (*emailContent != '\0')
    {
        currPos = GotoEndofLine(emailContent);
        
        for (auto item : _attributes)
        {
            if (std::strncmp(emailContent, item.GetKey().c_str(), std::min(strlen(emailContent), item.GetKey().size())) == 0)
            {
                currPos = item._parser(emailContent, item);
                continue;
            }
        } // end of inner loop

        ++currPos;
        emailContent += currPos;
    } // end of while loop

    return true;
}