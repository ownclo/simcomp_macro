#include <iostream>
#include <string>

#include "DeclarationFinder.h"

DefinitionTable DeclarationFinder::findDeclarations(SourceCodeStream& in_stream)
{
    DefinitionTable table;
    String line;

    while (in_stream.getLine(line))
    {
        Words line_words = getLineWords(line);
        if (is_declaration(line_words))
        {
            int decLine = in_stream.getLineNumber();

            String name = getMacroName(line_words);
            Words argnames = getMacroArgNames(line_words);
            String body = getMacroBody(in_stream, decLine);

            MacroDefinition macro(name, argnames, body);
            table.addMacro(macro);
        }
    }
    return table;
}

bool DeclarationFinder::is_declaration(const Words& line_words)
{
    if (line_words.size() < 2)
        return false;
    return line_words[1] == "macro";
}

String DeclarationFinder::getMacroName(const Words& line_words)
{
    return line_words[0];
}

Words DeclarationFinder::getMacroArgNames(const Words& line_words)
{
    return split(line_words[2], &Syntax::macro_delim);
}

String DeclarationFinder::getMacroBody(
        SourceCodeStream& in_stream,
        const int decLine)
{
    String line;
    std::stringstream ss;

    int i = 0;
    while(true)
    {
        if (not in_stream.getLine(line))
        {
            std::cerr << "ERROR: A macro definition never reached 'mend'\n";
            std::cerr << "------ Macro declared at line #" << decLine << "\n";
            exit(-1);
        }

        if (is_declaration(split(line, Syntax::spaces)))
        {
            std::cerr << "ERROR: Recursive declarations of macros are not supported\n";
            std::cerr << "------ First macro declared at line #" << decLine << "\n";
            std::cerr << "------ Secondary declaration at line #";
            std::cerr << in_stream.getLineNumber() << "\n";
            exit(-1);
        }

        if (line == "mend")
            break;

        if (i != 0) ss << "\n";
        ss << line;
        i++;
    }

    return ss.str();
}

Words DeclarationFinder::getLineWords(const String& line)
{
    return split(line, Syntax::spaces);
}
