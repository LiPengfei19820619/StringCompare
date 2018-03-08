#include "StringComparer.h"

using namespace std;

int StringComparer::Compare(const vector<ComparableSubString *> &sub_str_list1,
							const vector<ComparableSubString *> &sub_str_list2)
{
	vector<ComparableSubString *>::const_iterator it1;
	vector<ComparableSubString *>::const_iterator it2;

	for (it1 = sub_str_list1.begin(), it2 = sub_str_list2.begin();
		 it1 != sub_str_list1.end() && it2 != sub_str_list2.end();
		 it1++, it2++)
	{
		int result = (*it1)->Compare(*(*it2));
		if (result != 0)
		{
			return result;
		}
	}

	if (it1 == sub_str_list1.end() && it2 == sub_str_list2.end())
	{
		return 0;
	}
	if (it1 == sub_str_list1.end())
	{
		return -1;
	}

	return 1;
}