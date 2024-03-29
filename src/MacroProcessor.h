#ifndef MACROPROCESSOR_H
#define MACROPROCESSOR_H

#include "DefinitionTable.h"
#include "DeclarationFinder.h"
#include "MacroExpander.h"

class MacroProcessor {
private:

public:
    MacroProcessor();
    virtual ~MacroProcessor();

    void run(
        std::stringstream& in_stream,
        std::stringstream& out_stream);
};

#endif /* end of include guard: MACROPROCESSOR_H */
