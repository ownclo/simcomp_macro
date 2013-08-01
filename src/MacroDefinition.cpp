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

    for (Words::iterator it = _argnames.begin(); it != _argnames.end(); ++it)
    {
        String argname = *it;
        if (argname.length() > 0 && argname[0] != '&')
        {
            std::cerr << "WARNING: Parameter name does not begin with '&'.\n";
            std::cerr << "-------- Correct macro expansion is not guaranteed.\n";
            std::cerr << "-------- Macro named '" << _name << "'; ";
            std::cerr << " parameter named '" << argname << "'.\n";
        }
    }

    for (Words::iterator it = _argnames.begin(); it != _argnames.end(); ++it)
    {
        String argname = *it;
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

    if (val_size != names_size)
    {
        std::cerr << "ERROR: Wrong number of arguments for a macro '";
        std::cerr << name << "': " << val_size << " instead of " << names_size << "\n";
        std::cerr << "------ Argument names: ";
        copy(argnames.begin(), argnames.end(), std::ostream_iterator<String>(std::cout, " "));
        std::cerr << "\n";

        if (val_size > 0)
        {
            std::cerr << "------ Passed argument values: ";
            copy(argvalues.begin(), argvalues.end(), std::ostream_iterator<String>(std::cout, " "));
        }

        exit(-1);
    }

    String result = body;
    Words::const_iterator argvalue = argvalues.begin();
    Words::const_iterator argname = argnames.begin();
    while (argname != argnames.end() && argvalue != argvalues.end())
    {
        replaceAll(result, *argname, *argvalue);
        ++argname;
        ++argvalue;
    }

    return result;
}
