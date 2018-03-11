#include "Comparer/CompareRule.h"

#include "SubString/ComparableSubString.h"

#include <string>

using namespace std;


int CompareRule::Compare(const ComparableSubString &substr1,
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
		return -1;
	}

	return 1;
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
	if (result != 0)
	{
		return result;
	}

	if (substr1.GetLength() > substr2.GetLength())
	{
		return 1;
	}
	else if (substr1.GetLength() < substr2.GetLength())
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int CompareRule::CompareByStringCompare(const std::string &str1, const std::string &str2)
{
	return strcmp(str1.c_str(), str2.c_str());
}

int CompareRule::CompareByNumericValue(const std::string &str1, const std::string &str2)
{
	int result = CompareNumericValueByDigitCount(str1, str2);
	if (result != 0)
	{
		return result;
	}

	return CompareNumericValueByEachDigit(str1, str2);
}

int CompareRule::CompareNumericValueByDigitCount(const std::string &str1, const std::string &str2)
{
	if (str1.length() > str2.length())
	{
		return 1;
	}
	else if (str1.length() < str2.length())
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int CompareRule::CompareNumericValueByEachDigit(const std::string &str1, const std::string &str2)
{
	for (size_t i = 0; i < str1.length(); i++)
	{
		if (str1[i] > str2[i])
		{
			return 1;
		}
		else if (str1[i] < str2[i])
		{
			return -1;
		}
		else
		{

		}
	}

	return 0;
}
