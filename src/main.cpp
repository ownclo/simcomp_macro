#include <string>

#include "MacroProcessor.h"

int main(int argc, const char *argv[])
{
    const std::string infile = argv[1];
    const std::string outfile = argv[2];

    MacroProcessor macroProcessor(infile, outfile);

    macroProcessor.run();

    return 0;
}
