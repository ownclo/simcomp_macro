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

    // true if macro is found by name @param name;
    // if so, the macro is copied to @param macro.
    bool findMacro(const String& name, MacroDefinition& macro) const;
};

#endif /* end of include guard: DEFINITIONTABLE_H */
