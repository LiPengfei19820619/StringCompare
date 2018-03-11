#include "StringCompare.h"

#include "substring/ComparableSubString.h"
#include "splitter/StringSplitter.h"
#include "comparer/StringComparer.h"

using namespace std;

int StringCompare(const string &str1, const string &str2)
{
	vector<ComparableSubString *> sub_str_list1;
	vector<ComparableSubString *> sub_str_list2;

	if (!StringSplitter::Split(str1, sub_str_list1))
	{
		return STRING_COMPARE_RESULT_INVALID_STRING;
	}

	if (!StringSplitter::Split(str2, sub_str_list2))
	{
		return STRING_COMPARE_RESULT_INVALID_STRING;
	}

	return StringComparer::Compare(sub_str_list1, sub_str_list2);
}
