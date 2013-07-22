#include <assert.h>

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "MacroProcessor.h"

int main(int argc, const char *argv[])
{
    if (argc != 3) {
        std::cerr << "SimComp macroprocessor\n";
        std::cerr << "usage: $ macro INFILE OUTFILE\n";
        return -1;
    }

    const std::string in_fname = argv[1];
    const std::string out_fname = argv[2];

    std::ifstream in_file(in_fname.c_str());
    std::ofstream out_file(out_fname.c_str());

    assert(in_file);
    assert(out_file);

    std::stringstream in_contents;
    std::stringstream out_contents;

    // reading the whole input; character by character.
    // NOTE: should be replaced if it's a bottleneck.
    in_contents << in_file.rdbuf();

    MacroProcessor macroProcessor;
    macroProcessor.run(in_contents, out_contents);

    out_file << out_contents.str();
    return 0;
}
