#include <string>
#include <iostream>
#include <sstream>

#include "MacroProcessor.h"

MacroProcessor::MacroProcessor(void)
{
}

MacroProcessor::~MacroProcessor()
{
}

void MacroProcessor::run(
        std::stringstream& in_stream,
        std::stringstream& out_stream)
{
    SourceCodeStream codeStream(in_stream);
    std::stringstream filtered;
    DeclarationFinder declarationFinder;

    DefinitionTable table;
    table = declarationFinder.findDeclarations(codeStream, filtered);

    std::stringstream expanded;
    SourceCodeStream filteredSource(filtered);
    MacroExpander expander;
    expander.expand(table, filteredSource, expanded);

    out_stream << expanded.str();
}
