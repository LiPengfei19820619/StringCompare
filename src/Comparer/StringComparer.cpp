#include "StringComparer.h"

#include "CompareRule.h"
#include "StringCompare.h"

using namespace std;

int StringComparer::Compare(const vector<ComparableSubString *> &sub_str_list1,
							const vector<ComparableSubString *> &sub_str_list2)
{
	//vector<ComparableSubString *>::const_iterator it1;
	//vector<ComparableSubString *>::const_iterator it2;

	//for (it1 = sub_str_list1.begin(), it2 = sub_str_list2.begin();
	//	 it1 != sub_str_list1.end() && it2 != sub_str_list2.end();
	//	 it1++, it2++)
	//{
	//	int result = CompareRule::CompareTwoSubString(*(*it1), *(*it2)); //(*it1)->Compare(*(*it2));
	//	if (result != STRING_COMPARE_RESULT_EQUAL)
	//	{
	//		return result;
	//	}
	//}

	//if (it1 == sub_str_list1.end() && it2 == sub_str_list2.end())
	//{
	//	return STRING_COMPARE_RESULT_EQUAL;
	//}
	//if (it1 == sub_str_list1.end())
	//{
	//	return STRING_COMPARE_RESULT_LITTLE;
	//}

	return STRING_COMPARE_RESULT_GREATER;
}