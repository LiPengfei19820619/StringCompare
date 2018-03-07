#pragma once

#include "ComparableSubString.h"

#include <string>

class StringSplitter
{
public:
	static ComparableSubString *Split(const std::string &str);
};