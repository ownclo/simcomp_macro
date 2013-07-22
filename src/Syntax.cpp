#include "Syntax.h"

namespace Syntax {

bool is_blank(const std::string& line)
{
    std::size_t found = line.find_first_not_of(spaces);

    if (found == std::string::npos) // all spaces
        return true;

    return line[found] == comment_sym;
}

void trim_comments(std::string& line)
{
    std::size_t found = line.find(comment_sym);

    if (found != std::string::npos)
        line.erase(found, std::string::npos);

    trim_trailling_spaces(line);
}

void trim_trailling_spaces(std::string& line)
{
    std::size_t found = line.find_last_not_of(spaces);

    if (found != std::string::npos)
        line.erase(found+1, std::string::npos);
}

} // end of namespace Syntax
