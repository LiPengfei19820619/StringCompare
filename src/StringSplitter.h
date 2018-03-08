#pragma once

#include "ComparableSubString.h"

#include <string>
#include <vector>

class StringSplitter
{
public:
	static bool Split(const std::string &str, std::vector<ComparableSubString *> &substrs);
	static bool IsEscapeChar(char ch);
};