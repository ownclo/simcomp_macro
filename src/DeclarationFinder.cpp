#include <iostream>
#include <string>
#include <sstream>

#include "DeclarationFinder.h"

void DeclarationFinder::findDeclarations(
        std::stringstream& in_stream,
        DefinitionTable& table)
{
    std::string line;
    Words line_words;

    while (std::getline(in_stream, line))
    {
        Syntax::trim_comments(line);
        if (Syntax::is_blank(line))
            continue;

        line_words = split(line, Syntax::spaces);

        if (is_declaration(line_words))
            std::cout << line << "\n";
    }
}

bool DeclarationFinder::is_declaration(
        const Words& line_words)
{
    if (line_words.size() < 2)
        return false;
    return line_words[1] == "macro";
}
