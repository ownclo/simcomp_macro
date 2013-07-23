#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Common.h"
#include "Syntax.h"

class SourceCodeStream {
private:
    std::stringstream& in_stream;
    int lineNumber;

public:
    SourceCodeStream (std::stringstream& in_stream);

    bool getLine(String& res);
    int getLineNumber(void) const { return lineNumber; }

    virtual ~SourceCodeStream () {}
};

std::vector<String> split(
        const String& s,
        const String& delim);

#endif /* end of include guard: STRING_H */
