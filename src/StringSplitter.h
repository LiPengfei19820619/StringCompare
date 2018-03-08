#pragma once

#include "ComparableSubString.h"

#include <string>
#include <vector>

class StringSplitter
{
public:
	static bool Split(const std::string &str, std::vector<ComparableSubString *> &substrs);

private:
	static ComparableSubString *SplitASubString(const std::string &str, size_t begin_pos, size_t &end_pos);
	static bool CurrentPosIsChar(const std::string &str, size_t begin_pos);
	static bool CurrentPosIsDigit(const std::string &str, size_t begin_pos);
	static bool IsEscapeChar(char ch);
};