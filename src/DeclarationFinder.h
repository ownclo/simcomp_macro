#ifndef DECLARATIONFINDER_H
#define DECLARATIONFINDER_H

#include <vector>
#include <string>
#include <sstream>

#include "Common.h"

#include "DefinitionTable.h"
#include "Syntax.h"
#include "SourceCodeStream.h"

class DeclarationFinder {
public:
    DeclarationFinder () {}
    virtual ~DeclarationFinder () {}

    DefinitionTable findDeclarations(
            SourceCodeStream& in_stream,
            std::stringstream& out_stream);

private:
    // for line to be a declaration, the second
    // word must be 'macro'
    bool is_declaration(const Words& line_words);

    String getMacroName(const Words& line_words);
    Words getMacroArgNames(const Words& line_words);
    String getMacroBody(SourceCodeStream& in_stream, const int decLine);
};

#endif /* end of include guard: DECLARATIONFINDER_H */
