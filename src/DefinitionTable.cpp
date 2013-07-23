#include <iostream>

#include "DefinitionTable.h"

void DefinitionTable::addMacro(MacroDefinition macro)
{
    String name = macro.getName();
    if (macros.find(name) != macros.end())
    {
        std::cerr << "ERROR: Redeclaration of macro '" << name << "'.\n";
        exit(-1);
    }

    macros[name] = macro;
}

bool DefinitionTable::findMacro(
        const String& name,
        MacroDefinition& macro) const
{
    if (macros.find(name) == macros.end()) {
        return false;
    }

    macro = macros.at(name);
    return true;
}
