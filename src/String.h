#ifndef STRING_H
#define STRING_H

/* std::string manipulations */

#include <vector>
#include <algorithm>
#include <string>

std::vector<std::string> split(
        const std::string& s,
        const std::string& delim);

void replaceAll(
	std::string& str,
	const std::string& from,
	const std::string& to);

#endif /* end of include guard: STRING_H */
