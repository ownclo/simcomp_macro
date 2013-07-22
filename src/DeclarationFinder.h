#ifndef DECLARATIONFINDER_H
#define DECLARATIONFINDER_H

#include <vector>
#include <string>
#include <sstream>

#include "DefinitionTable.h"
#include "Syntax.h"
#include "String.h"

typedef std::vector<std::string> Words;

class DeclarationFinder {
public:

    DeclarationFinder () {}
    virtual ~DeclarationFinder () {}

    void findDeclarations(
            std::stringstream& in_stream,
            DefinitionTable& table);

    // for line to be a declaration, the second
    // word must be 'macro'
    bool is_declaration(const Words& line_words);
};

#endif /* end of include guard: DECLARATIONFINDER_H */
