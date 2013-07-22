#include <string>
#include <iostream>

#include "MacroProcessor.h"

int main(int argc, const char *argv[])
{
    if (argc != 3) {
        std::cerr << "SimComp macroprocessor\n";
        std::cerr << "usage: $ macro INFILE OUTFILE\n";
        return -1;
    }

    const std::string infile = argv[1];
    const std::string outfile = argv[2];

    MacroProcessor macroProcessor;
    macroProcessor.run(infile, outfile);

    return 0;
}
