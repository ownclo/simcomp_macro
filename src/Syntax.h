#ifndef SYNTAX_H
#define SYNTAX_H

#include <string>

namespace Syntax {
    static const char comment_sym = ';';
    static std::string spaces(" \r\t\n");

    bool is_blank(const std::string& line);

    void trim_comments(std::string& line);
    void trim_trailling_spaces(std::string& line);
} // namespace Syntax

#endif /* end of include guard: SYNTAX_H */
