#ifndef MACRODEFINITION_H
#define MACRODEFINITION_H

#include <string>

#include "Common.h"

class MacroDefinition {
private:
    String name;
    Words argnames;
    String body;

public:
    MacroDefinition() {}

    MacroDefinition(
            String name,
            Words argnames,
            String body);

    virtual ~MacroDefinition () {}

    String getName (void) const { return name; }
};

#endif /* end of include guard: MACRODEFINITION_H */
