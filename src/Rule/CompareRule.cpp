#include "Rule/CompareRule.h"

#include "SubString/ComparableSubString.h"
#include "StringCompare.h"
#include <string>

using namespace std;


int CompareRule::Compare(const vector<ComparableSubString *> &sub_str_list1,
	                     const vector<ComparableSubString *> &sub_str_list2)
{
	// 规则(1)从左到右分离单纯的子字母串（均为字母）和子数字串（均为数字）进行比较
	int result = CompareAllSubStringInOrder(sub_str_list1, sub_str_list2);

	if (result != STRING_COMPARE_RESULT_EQUAL)
	{
		return result;
	}

	// 规则(2)如果一边已无子串（子字母串或子数字串），另外一方还有子串，则无子串的小；如果双方均无子串，则相等
	// 此规则可以理解为：前面比较的所有的子串都相等的情况下，则比较子串个数
	// 字串个数小的一方为小，子串个数一样的话则相等
	return CompareSubStringCount(sub_str_list1, sub_str_list2);
}

// 从左到右依次比较所有的子串
int CompareRule::CompareAllSubStringInOrder(const vector<ComparableSubString *> &sub_str_list1,
	                                       const vector<ComparableSubString *> &sub_str_list2)
{
	vector<ComparableSubString *>::const_iterator it1;
	vector<ComparableSubString *>::const_iterator it2;

	for (it1 = sub_str_list1.begin(), it2 = sub_str_list2.begin();
		it1 != sub_str_list1.end() && it2 != sub_str_list2.end();
		it1++, it2++)
	{
		int result = CompareTwoSubString(*(*it1), *(*it2));

		// 规则(6)如果当前子串相等，才需要比较下一个子串
		if (result != STRING_COMPARE_RESULT_EQUAL)
		{
			return result;
		}
	}

	return STRING_COMPARE_RESULT_EQUAL;
}

int CompareRule::CompareSubStringCount(const vector<ComparableSubString *> &sub_str_list1,
	                                   const vector<ComparableSubString *> &sub_str_list2)
{
	return CompareTwoValues<size_t>(sub_str_list1.size(), sub_str_list2.size());
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
	// 规则(3)如果被比较的一边是子数字串，一边是子字母串，则子数字串小；
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

	// 规则(4)如果被比较的都是子字母串，则按C库strcmp的规则比较子字母串大小
	return CompareByStringCompare(value1, value2);
}

int CompareRule::CompareTwoDigitSubString(const ComparableSubString &substr1,
										  const ComparableSubString &substr2)
{
	string value1;
	string value2;

	substr1.GetValue(value1);
	substr2.GetValue(value2);

	// 规则(5)如果被比较的都是子数字串，则按数值比较规则比较大小，如果值相等，则子数字串短的一方（前面的0少）小；
	int result = CompareByNumericValue(value1, value2);
	if (result != STRING_COMPARE_RESULT_EQUAL)
	{
		return result;
	}

	// 规则(5)如果被比较的都是子数字串，则按数值比较规则比较大小，如果值相等，则子数字串短的一方（前面的0少）小；
	return CompareTwoValues<size_t>(substr1.GetLength(), substr2.GetLength());
}

int CompareRule::CompareByStringCompare(const std::string &str1, const std::string &str2)
{
	return strcmp(str1.c_str(), str2.c_str());
}

// 比较两个十进制数字字符串的数值大小
int CompareRule::CompareByNumericValue(const std::string &str1, const std::string &str2)
{
	// 由于子串类GetValue返回的十进制数字字符串，已经是只包含有效数字的串，数字前面的无效0已经去掉了
	// 所以可以直接根据数值的位数来比较大小
	int result = CompareNumericValueByDigitCount(str1, str2);
	if (result != STRING_COMPARE_RESULT_EQUAL)
	{
		return result;
	}

	// 两个数值的位数相同，则从左到右依次(从高位到低位)比较每个数字
	return CompareNumericValueByEachDigit(str1, str2);
}

int CompareRule::CompareNumericValueByDigitCount(const std::string &str1, const std::string &str2)
{
	return CompareTwoValues<size_t>(str1.length(), str2.length());
}

// 从高位到地位依次比较每一位十进制数字的大小
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
