#include <algorithm>
#include <cstring>
#include <iostream>

#include "Tools.hpp"
#include "ItemParser.hpp"

#include "EmailParser.hpp"

using namespace std;

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
    _attributes.emplace(_attributes.end(), EmailAttr("References:", PARSERS::ReferenceParser));
    _attributes.emplace(_attributes.end(), EmailAttr("From:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("To:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("Cc:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("Subject:", PARSERS::OneLineAttrParser));
    _attributes.emplace(_attributes.end(), EmailAttr("Content-Type:", PARSERS::ContentAttrParser, true));
}

bool EmailParser::parse(const char *emailContent)
{
    uint32_t currPos = 0;
    
    while (*emailContent != '\0')
    {
        currPos = Util::GotoEndofLine(emailContent);
        
        for (auto item : _attributes)
        {
            if ( (!item.isFound() || item.isMultiple()) && 
                std::strncmp(emailContent, item.GetKey().c_str(), std::min(strlen(emailContent), item.GetKey().size())) == 0)
            {
                currPos = item._parser(emailContent, item, currPos);
                item.setFound();
                break;
            }
        } // end of inner loop

        emailContent += currPos;
    } // end of while loop

    return true;
}