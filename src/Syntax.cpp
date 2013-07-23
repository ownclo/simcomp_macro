#include "Syntax.h"

namespace Syntax {

bool is_blank(const String& line)
{
    std::size_t found = line.find_first_not_of(spaces);

    if (found == String::npos) // all spaces
        return true;

    return line[found] == comment_sym;
}

void trim_comments(String& line)
{
    std::size_t found = line.find(comment_sym);

    if (found != String::npos)
        line.erase(found, String::npos);

    trim_trailling_spaces(line);
}

void trim_trailling_spaces(String& line)
{
    std::size_t found = line.find_last_not_of(spaces);

    if (found != String::npos)
        line.erase(found+1, String::npos);
}

} // end of namespace Syntax
