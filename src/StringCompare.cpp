#include "StringCompare.h"

#include "substring/ComparableSubString.h"
#include "splitter/StringSplitter.h"
#include "rule/CompareRule.h"

using namespace std;


void ClearSubStringList(vector<ComparableSubString *> &sub_str_list);

int StringCompare(const string &str1, const string &str2)
{
	vector<ComparableSubString *> sub_str_list1;
	vector<ComparableSubString *> sub_str_list2;

	if (!StringSplitter::Split(str1, sub_str_list1))
	{
		ClearSubStringList(sub_str_list1);
		return STRING_COMPARE_RESULT_INVALID_STRING;
	}

	if (!StringSplitter::Split(str2, sub_str_list2))
	{
		ClearSubStringList(sub_str_list1);
		ClearSubStringList(sub_str_list2);
		return STRING_COMPARE_RESULT_INVALID_STRING;
	}

	int result =  CompareRule::Compare(sub_str_list1, sub_str_list2);

	ClearSubStringList(sub_str_list1);
	ClearSubStringList(sub_str_list2);

	return result;
}

void ClearSubStringList(vector<ComparableSubString *> &sub_str_list)
{
	vector<ComparableSubString *>::iterator it;

	for (it = sub_str_list.begin(); it != sub_str_list.end(); it++)
	{
		ComparableSubString *sub_str = (*it);

		delete sub_str;
	}

	sub_str_list.clear();
}
