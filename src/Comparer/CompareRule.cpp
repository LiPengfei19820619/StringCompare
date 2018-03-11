#include "Comparer/CompareRule.h"

#include "SubString/ComparableSubString.h"

#include "StringCompare.h"

#include <string>

using namespace std;


int CompareRule::Compare(const vector<ComparableSubString *> &sub_str_list1,
	                     const vector<ComparableSubString *> &sub_str_list2)
{
	vector<ComparableSubString *>::const_iterator it1;
	vector<ComparableSubString *>::const_iterator it2;

	for (it1 = sub_str_list1.begin(), it2 = sub_str_list2.begin();
		it1 != sub_str_list1.end() && it2 != sub_str_list2.end();
		it1++, it2++)
	{
		int result = CompareRule::CompareTwoSubString(*(*it1), *(*it2)); //(*it1)->Compare(*(*it2));
		if (result != STRING_COMPARE_RESULT_EQUAL)
		{
			return result;
		}
	}

	if (it1 == sub_str_list1.end() && it2 == sub_str_list2.end())
	{
		return STRING_COMPARE_RESULT_EQUAL;
	}
	if (it1 == sub_str_list1.end())
	{
		return STRING_COMPARE_RESULT_LITTLE;
	}

	return STRING_COMPARE_RESULT_GREATER;
}

int CompareRule::CompareTwoSubString(const ComparableSubString &substr1,
			const ComparableSubString &substr2)
{
	if (substr1.GetType() != substr2.GetType())
	{
		return CompareDifferentTypeSubString(substr1, substr2);
	}

	if (substr1.GetType() == ComparableSubString::SUBSTRING_TYPE_CHAR)
	{
		return CompareTwoCharSubString(substr1, substr2);
	}

	return CompareTwoDigitSubString(substr1, substr2);
}

int CompareRule::CompareDifferentTypeSubString(const ComparableSubString &substr1,
								  const ComparableSubString &substr2)
{
	if (substr1.GetType() == ComparableSubString::SUBSTRING_TYPE_NUMBER)
	{
		return STRING_COMPARE_RESULT_LITTLE;
	}

	return STRING_COMPARE_RESULT_GREATER;
}

int CompareRule::CompareTwoCharSubString(const ComparableSubString &substr1,
							const ComparableSubString &substr2)
{
	string value1;
	string value2;

	substr1.GetValue(value1);
	substr2.GetValue(value2);

	return CompareByStringCompare(value1, value2);
}

int CompareRule::CompareTwoDigitSubString(const ComparableSubString &substr1,
										  const ComparableSubString &substr2)
{
	string value1;
	string value2;

	substr1.GetValue(value1);
	substr2.GetValue(value2);

	int result = CompareByNumericValue(value1, value2);
	if (result != STRING_COMPARE_RESULT_EQUAL)
	{
		return result;
	}

	return CompareTwoValues<size_t>(substr1.GetLength(), substr2.GetLength());
}

int CompareRule::CompareByStringCompare(const std::string &str1, const std::string &str2)
{
	return strcmp(str1.c_str(), str2.c_str());
}

int CompareRule::CompareByNumericValue(const std::string &str1, const std::string &str2)
{
	int result = CompareNumericValueByDigitCount(str1, str2);
	if (result != STRING_COMPARE_RESULT_EQUAL)
	{
		return result;
	}

	return CompareNumericValueByEachDigit(str1, str2);
}

int CompareRule::CompareNumericValueByDigitCount(const std::string &str1, const std::string &str2)
{
	return CompareTwoValues<size_t>(str1.length(), str2.length());
}

int CompareRule::CompareNumericValueByEachDigit(const std::string &str1, const std::string &str2)
{
	for (size_t i = 0; i < str1.length(); i++)
	{
		int result = CompareTwoValues<char>(str1[i], str2[i]);
		if (result != STRING_COMPARE_RESULT_EQUAL)
		{
			return result;
		}
	}

	return STRING_COMPARE_RESULT_EQUAL;
}

template<typename T>
static int CompareRule::CompareTwoValues(T value1, T value2)
{
	if (value1 > value2)
	{
		return STRING_COMPARE_RESULT_GREATER;
	}
	else if (value1 < value2)
	{
		return STRING_COMPARE_RESULT_LITTLE;
	}
	else
	{
		return STRING_COMPARE_RESULT_EQUAL;
	}
}
