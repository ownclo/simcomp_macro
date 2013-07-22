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
    DeclarationFinder declarationFinder;
    DefinitionTable table;

    declarationFinder.findDeclarations(in_stream, table);

    out_stream << "MacroProcessor is wired up!\n";
    // std::cout << table.printTable();
}
