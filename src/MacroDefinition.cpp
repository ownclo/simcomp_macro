#include <iostream>

#include "MacroDefinition.h"

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
