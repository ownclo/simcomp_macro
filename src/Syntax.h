#ifndef SYNTAX_H
#define SYNTAX_H

#include "Common.h"
#include "String.h"

namespace Syntax {
    static const char comment_sym = ';';
    static const char macro_delim = ',';
    static const char param_delim = ',';

    static String spaces(" \r\t\n");

    bool is_blank(const String& line);

    void trim_comments(String& line);
    void trim_trailling_spaces(String& line);

    Words getLineWords(const String& line);

} // namespace Syntax

#endif /* end of include guard: SYNTAX_H */
