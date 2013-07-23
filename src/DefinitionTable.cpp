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

MacroDefinition DefinitionTable::findMacro(const String& name)
{
    if (macros.find(name) == macros.end())
    {
        std::cerr << "ERROR: '" << name << "' macro is used undefined.\n";
        exit(-1);
    }

    return macros[name];
}
