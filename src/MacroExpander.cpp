#include <algorithm> // for copy and find
#include <iterator> // for ostream_iterator.

#include "MacroExpander.h"

void MacroExpander::expand(
        const DefinitionTable& table,
        SourceCodeStream& filteredSource,
        std::stringstream& expanded_stream)
{
    String result;
    Words stack_trace;
    recursively_expand(table, filteredSource, stack_trace, result);
    expanded_stream << result;
}

void MacroExpander::recursively_expand(
        const DefinitionTable& table,
        SourceCodeStream& filteredSource,
        Words& stack_trace,
        String& result)
{
    String line;
    String expanded_macro;
    Words argvalues;
    MacroDefinition macro;

    while (filteredSource.getLine(line))
    {
        Words line_words = Syntax::getLineWords(line);
        if (isInvocation(line_words, table, macro))
        {
            argvalues = getArgValues(line_words);
            String name = macro.getName();

            assert_not_in_stack(stack_trace, name);

            Words new_stack_trace = stack_trace;
            new_stack_trace.push_back(name);

            expanded_macro = macro.expand(argvalues);

            std::stringstream first_expanded_stream(expanded_macro);
            SourceCodeStream first_expanded(first_expanded_stream);
            String finally_expanded;

            recursively_expand(table, first_expanded, new_stack_trace, finally_expanded);
            result += Syntax::line_comment + line + "\n";
            result += finally_expanded;
        }
        else result += line + "\n";
    }
}

bool MacroExpander::isInvocation(
        const Words& line_words,
        const DefinitionTable& table,
        MacroDefinition& macro)
{
    if (line_words.size() == 0)
        return false;

    String macro_name = line_words[0];
    return table.findMacro(macro_name, macro);
}

Words MacroExpander::getArgValues(const Words& line_words)
{
    if (line_words.size() < 2)
        return Words();

    if (line_words.size() > 2)
    {
        std::cerr << "ERROR: Syntactically incorrect invocation of macro '";
        std::cerr << line_words[0] << "'. Spaces between arguments are not allowed.\n";
        std::cerr << "------ Macro invocation:";
        copy(line_words.begin(), line_words.end(), std::ostream_iterator<String>(std::cout, " "));
        std::cerr << "\n";
        exit(-1);
    }

    return split(line_words[1], &Syntax::param_delim);
}

void MacroExpander::assert_not_in_stack(
        const Words& stack_trace,
        const String& name)
{
    if (is_in_stack(stack_trace, name))
    {
        std::cerr << "ERROR: Recursively defined macros used.\n";
        std::cerr << "------ Stack trace: ";
        copy(stack_trace.begin(), stack_trace.end(), std::ostream_iterator<String>(std::cout, " "));
        std::cerr << "\n";
        exit(-1);
    }
}

bool MacroExpander::is_in_stack(
        const Words& stack_trace,
        const String& name)
{
    Words::const_iterator found;
    found = std::find(stack_trace.begin(), stack_trace.end(), name);

    return found != stack_trace.end();
}
