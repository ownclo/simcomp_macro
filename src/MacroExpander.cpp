#include <algorithm> // for copy.
#include <iterator> // for ostream_iterator.

#include "MacroExpander.h"

void MacroExpander::expand(
        const DefinitionTable& table,
        SourceCodeStream& filteredSource,
        std::stringstream& expanded_stream)
{
    String line;
    String expanded_macro;
    Words argvalues;
    MacroDefinition macro;

    while (filteredSource.getLine(line))
    {
        Words line_words = Syntax::getLineWords(line);
        if (isInvocation(line_words, table, macro))
        {
            argvalues = getArgValues(line_words);
            expanded_macro = macro.expand(argvalues);

            // XXX: Inner macros will not be expanded.

            expanded_stream << expanded_macro << "\n";
        }
        else expanded_stream << line << "\n";
    }
}

bool MacroExpander::isInvocation(
        const Words& line_words,
        const DefinitionTable& table,
        MacroDefinition& macro)
{
    if (line_words.size() == 0)
        return false;

    String macro_name = line_words[0];
    return table.findMacro(macro_name, macro);
}

Words MacroExpander::getArgValues(const Words& line_words)
{
    if (line_words.size() < 2)
        return {""};

    if (line_words.size() > 2)
    {
        std::cerr << "ERROR: Syntactically incorrect invocation of macro '";
        std::cerr << line_words[0] << "'. Spaces between arguments are not allowed.\n";
        std::cerr << "------ Macro invocation:";
        copy(line_words.begin(), line_words.end(), std::ostream_iterator<String>(std::cout, " "));
        std::cerr << "\n";
        exit(-1);
    }

    return split(line_words[1], &Syntax::param_delim);
}
