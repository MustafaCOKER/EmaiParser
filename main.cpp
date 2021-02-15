#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>

#include "EmailParser.hpp"

using namespace std;

char *fileContent = new char[65535];

void readFile()
{
    std::ifstream infile("emailInstance.txt");
    std::stringstream iss;
    std::string line;
    
    while (std::getline(infile, line))
        iss << line << std::endl;
    
    std::memcpy(fileContent, iss.str().c_str(), iss.str().size() );
}

int main()
{

    // std::memset(fileContent, 0, sizeof(fileContent));

    readFile();
    
    EmailParser parser;
    parser.parse(fileContent);

    return 0;
}