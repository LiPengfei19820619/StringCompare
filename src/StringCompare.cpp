#include "StringCompare.h"

#include "ComparableSubString.h"
#include "StringSplitter.h"
#include "StringComparer.h"

using namespace std;

int StringCompare(const string &str1, const string &str2)
{
	vector<ComparableSubString *> sub_str_list1;
	vector<ComparableSubString *> sub_str_list2;

	StringSplitter::Split(str1, sub_str_list1);
	StringSplitter::Split(str2, sub_str_list2);

	return StringComparer::Compare(sub_str_list1, sub_str_list2);
}
