#ifndef MACROEXPANDER_H
#define MACROEXPANDER_H

#include <sstream>

#include "Common.h"
#include "String.h"

#include "DefinitionTable.h"
#include "SourceCodeStream.h"

class MacroExpander {
public:
    MacroExpander () {}
    virtual ~MacroExpander () {}

    void expand(const DefinitionTable& table,
            SourceCodeStream& filteredSource,
            std::stringstream& expanded);

private:
    bool isInvocation(
            const Words& line_words,
            const DefinitionTable& table,
            MacroDefinition& macro);

    Words getArgValues(const Words& line_words);
};

#endif /* end of include guard: MACROEXPANDER_H */
