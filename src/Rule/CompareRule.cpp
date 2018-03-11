#include "Rule/CompareRule.h"

#include "SubString/ComparableSubString.h"
#include "StringCompare.h"
#include <string>

using namespace std;


int CompareRule::Compare(const vector<ComparableSubString *> &sub_str_list1,
	                     const vector<ComparableSubString *> &sub_str_list2)
{
	// ����(1)�����ҷ��뵥��������ĸ������Ϊ��ĸ���������ִ�����Ϊ���֣����бȽ�
	int result = CompareAllSubStringInOrder(sub_str_list1, sub_str_list2);

	if (result != STRING_COMPARE_RESULT_EQUAL)
	{
		return result;
	}

	// ����(2)���һ�������Ӵ�������ĸ���������ִ���������һ�������Ӵ��������Ӵ���С�����˫�������Ӵ��������
	// �˹���������Ϊ��ǰ��Ƚϵ����е��Ӵ�����ȵ�����£���Ƚ��Ӵ�����
	// �ִ�����С��һ��ΪС���Ӵ�����һ���Ļ������
	return CompareSubStringCount(sub_str_list1, sub_str_list2);
}

// ���������αȽ����е��Ӵ�
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

		// ����(6)�����ǰ�Ӵ���ȣ�����Ҫ�Ƚ���һ���Ӵ�
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
	// ����(3)������Ƚϵ�һ���������ִ���һ��������ĸ�����������ִ�С��
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

	// ����(4)������ȽϵĶ�������ĸ������C��strcmp�Ĺ���Ƚ�����ĸ����С
	return CompareByStringCompare(value1, value2);
}

int CompareRule::CompareTwoDigitSubString(const ComparableSubString &substr1,
										  const ComparableSubString &substr2)
{
	string value1;
	string value2;

	substr1.GetValue(value1);
	substr2.GetValue(value2);

	// ����(5)������ȽϵĶ��������ִ�������ֵ�ȽϹ���Ƚϴ�С�����ֵ��ȣ��������ִ��̵�һ����ǰ���0�٣�С��
	int result = CompareByNumericValue(value1, value2);
	if (result != STRING_COMPARE_RESULT_EQUAL)
	{
		return result;
	}

	// ����(5)������ȽϵĶ��������ִ�������ֵ�ȽϹ���Ƚϴ�С�����ֵ��ȣ��������ִ��̵�һ����ǰ���0�٣�С��
	return CompareTwoValues<size_t>(substr1.GetLength(), substr2.GetLength());
}

int CompareRule::CompareByStringCompare(const std::string &str1, const std::string &str2)
{
	return strcmp(str1.c_str(), str2.c_str());
}

// �Ƚ�����ʮ���������ַ�������ֵ��С
int CompareRule::CompareByNumericValue(const std::string &str1, const std::string &str2)
{
	// �����Ӵ���GetValue���ص�ʮ���������ַ������Ѿ���ֻ������Ч���ֵĴ�������ǰ�����Ч0�Ѿ�ȥ����
	// ���Կ���ֱ�Ӹ�����ֵ��λ�����Ƚϴ�С
	int result = CompareNumericValueByDigitCount(str1, str2);
	if (result != STRING_COMPARE_RESULT_EQUAL)
	{
		return result;
	}

	// ������ֵ��λ����ͬ�������������(�Ӹ�λ����λ)�Ƚ�ÿ������
	return CompareNumericValueByEachDigit(str1, str2);
}

int CompareRule::CompareNumericValueByDigitCount(const std::string &str1, const std::string &str2)
{
	return CompareTwoValues<size_t>(str1.length(), str2.length());
}

// �Ӹ�λ����λ���αȽ�ÿһλʮ�������ֵĴ�С
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
