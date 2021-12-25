#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>

#include "EmailParser.hpp"

using namespace std;

constexpr uint32_t MB1 = 1024 * 1024;
constexpr uint32_t CONTENT_SIZE = 50 * MB1;
char *fileContent = new char[CONTENT_SIZE];

void readFile(const char *const path)
{
    std::ifstream infile(path);

    if (!infile.is_open())
    {
        std::cerr << "File Could Not opened\n";
        exit(-1);
    }

    std::stringstream iss;
    std::string line;

    while (std::getline(infile, line))
        iss << line << std::endl;

    std::memcpy(fileContent, iss.str().c_str(), iss.str().size());
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "USAGE : ./EmailParser sampleEmailFile\n";
        exit(-1);
    }

    memset(fileContent, 0, CONTENT_SIZE);

    readFile(argv[1]);

    EmailParser parser;
    parser.parse(fileContent);

    return 0;
}