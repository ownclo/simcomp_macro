#include <string>
#include <iostream>

#include "MacroProcessor.h"

MacroProcessor::MacroProcessor(void)
{
}

void MacroProcessor::run(
        const std::string infile,
        const std::string outfile)
{
    std::cout << infile << "\n" << outfile << "\n";
}
