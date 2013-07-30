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
    void recursively_expand(
            const DefinitionTable& table,
            SourceCodeStream& filteredSource,
            Words& stack_trace,
            String& result);

    bool isInvocation(
            const Words& line_words,
            const DefinitionTable& table,
            MacroDefinition& macro);

    Words getArgValues(const Words& line_words);

    void assert_not_in_stack(
            const Words& stack_trace,
            const String& name);

    bool is_in_stack(
            const Words& stack_trace,
            const String& name);
};

#endif /* end of include guard: MACROEXPANDER_H */
