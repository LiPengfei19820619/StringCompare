#pragma once

#include <string>

class ComparableSubString;

class CompareRule
{
public:
	static int Compare(const ComparableSubString &substr1,
					   const ComparableSubString &substr2);

private:
	static int CompareDifferentTypeSubString(const ComparableSubString &substr1,
											 const ComparableSubString &substr2);
	static int CompareTwoCharSubString(const ComparableSubString &substr1,
											 const ComparableSubString &substr2);
	static int CompareTwoDigitSubString(const ComparableSubString &substr1,
									   const ComparableSubString &substr2);

	static int CompareByStringCompare(const std::string &str1, const std::string &str2);
	static int CompareByNumericValue(const std::string &str1, const std::string &str2);

	static int CompareNumericValueByDigitCount(const std::string &str1, const std::string &str2);
	static int CompareNumericValueByEachDigit(const std::string &str1, const std::string &str2);
};
