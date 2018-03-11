#pragma once

#include <string>
#include <vector>

class ComparableSubString;

class CompareRule
{
public:
	static int Compare(const std::vector<ComparableSubString *> &sub_str_list1,
		               const std::vector<ComparableSubString *> &sub_str_list2);

private:
	static int CompareAllSubStringInOrder(const std::vector<ComparableSubString *> &sub_str_list1,
		                                 const std::vector<ComparableSubString *> &sub_str_list2);
	static int CompareSubStringCount(const std::vector<ComparableSubString *> &sub_str_list1,
		                             const std::vector<ComparableSubString *> &sub_str_list2);

	static int CompareTwoSubString(const ComparableSubString &substr1,
		                           const ComparableSubString &substr2);

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

	template<typename T>
	static int CompareTwoValues(T value1, T value2);
};
