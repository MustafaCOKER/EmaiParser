#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>

#include "EmailParser.hpp"

using namespace std;

constexpr uint32_t MB1 = 1024*1024;
constexpr uint32_t CONTENT_SIZE = 50*MB1;
char *fileContent = new char[CONTENT_SIZE];

void readFile()
{
    std::ifstream infile("rawEmail.eml");
    std::stringstream iss;
    std::string line;
    
    while (std::getline(infile, line))
        iss << line << std::endl;
    
    std::memcpy(fileContent, iss.str().c_str(), iss.str().size() );
}

int main()
{
    memset(fileContent, 0, CONTENT_SIZE);

    readFile();

    EmailParser parser;
    parser.parse(fileContent);

    return 0;
}