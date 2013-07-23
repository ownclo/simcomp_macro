#include "SourceCodeStream.h"

SourceCodeStream::SourceCodeStream (std::stringstream& _in_stream)
    : in_stream(_in_stream)
{
        lineNumber = 0;
}

bool SourceCodeStream::getLine(String& res)
{
    while (std::getline(in_stream, res))
    {
        lineNumber++;

        Syntax::trim_comments(res);
        if (Syntax::is_blank(res))
            continue;

        return true;
    }
    return false;
}
