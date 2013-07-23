#ifndef DEFINITIONTABLE_H
#define DEFINITIONTABLE_H

#include <unordered_map>

#include "Common.h"
#include "MacroDefinition.h"

class DefinitionTable {
private:
    std::unordered_map<String, MacroDefinition> macros;

public:
    DefinitionTable () {}
    virtual ~DefinitionTable () {}

    void addMacro(MacroDefinition macro);
    MacroDefinition findMacro(const String& name);
};

#endif /* end of include guard: DEFINITIONTABLE_H */
