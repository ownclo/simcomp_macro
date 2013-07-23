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

using namespace std;

vector<string> split(
        const string& str,
        const string& delimiters = " ")
{
    vector<string> result;

    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        result.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
    return result;
}
