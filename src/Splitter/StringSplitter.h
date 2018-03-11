#pragma once

#include "substring/ComparableSubString.h"

#include <string>
#include <vector>

class StringSplitter
{
public:
	static bool Split(const std::string &str, std::vector<ComparableSubString *> &substrs);

private:
	static ComparableSubString *SplitASubString(const std::string &str, size_t &cur_pos);

	static std::string SplitACharSubString(const std::string &str, size_t &cur_pos);
	static std::string SplitADigitSubString(const std::string &str, size_t &cur_pos);

	static std::string GetAllEscapedCharForCharSubString(const std::string &str, size_t &cur_pos);

	static bool ReachMaxEscapeCharNum(int escaped_len);

	static bool CurrentPosIsChar(const std::string &str, size_t begin_pos);
	static bool CurrentPosIsDigit(const std::string &str, size_t begin_pos);
	static bool IsEscapeChar(char ch);

	static const int MAX_ESCAPE_CHAR_NUM = 3;
};