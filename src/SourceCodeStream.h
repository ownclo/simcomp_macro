#ifndef SOURCE_CODE_STREAM_H
#define SOURCE_CODE_STREAM_H

#include <iostream>
#include <sstream>

#include "Common.h"
#include "Syntax.h"
#include "String.h"

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

#endif /* end of include guard: SOURCE_CODE_STREAM_H */
