#include <iostream>
#include <algorithm> // for copy.
#include <iterator> // for ostream_iterator.

#include "MacroDefinition.h"
#include "String.h"

MacroDefinition::MacroDefinition(
        String _name,
        Words _argnames,
        String _body)
{
    if (_name.length() <= 1)
    {
        std::cerr << "WARNING: Macro name seemes to be too short.\n";
        std::cerr << "-------- In the definition of '" << _name << "'.\n";
    }

    for (auto &argname : _argnames)
    {
        if (argname.length() > 0 && argname[0] != '&')
        {
            std::cerr << "WARNING: Parameter name does not begin with '&'.\n";
            std::cerr << "-------- Correct macro expansion is not guaranteed.\n";
            std::cerr << "-------- Macro named '" << _name << "'; ";
            std::cerr << " parameter named '" << argname << "'.\n";
        }
    }

    for (auto &argname : _argnames)
    {
        if (_body.find(argname) == String::npos)
        {
            std::cerr << "WARNING: Unused parameter '" << argname;
            std::cerr << "' in macro '" << _name << "'.\n";
        }
    }

    name = _name;
    argnames = _argnames;
    body = _body;
}

String MacroDefinition::expand(const Words& argvalues) const
{
    const size_t val_size = argvalues.size();
    const size_t names_size = argnames.size();

    if (argvalues.size() != argnames.size())
    {
        std::cerr << "ERROR: Wrong number of arguments for a macro '";
        std::cerr << name << "': " << val_size << " instead of " << names_size << "\n";
        std::cerr << "------ Argument names: ";
        copy(argnames.begin(), argnames.end(), std::ostream_iterator<String>(std::cout, " "));
        std::cerr << "\n";

        if (argvalues.size() > 0)
        {
            std::cerr << "------ Passed argument values: ";
            copy(argvalues.begin(), argvalues.end(), std::ostream_iterator<String>(std::cout, " "));
        }

        exit(-1);
    }

    String result = body;
    Words::const_iterator argvalue = argvalues.begin();
    for (const auto &argname : argnames)
    {
        replaceAll(result, argname, *argvalue);
        ++argvalue;
    }

    return result;
}
