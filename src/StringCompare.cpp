#include "StringCompare.h"

#include "ComparableSubString.h"
#include "StringSplitter.h"
#include "StringComparer.h"

int StringCompare(const std::string &str1, const std::string &str2)
{
	std::vector<ComparableSubString *> sub_str_list1;
	std::vector<ComparableSubString *> sub_str_list2;

	StringSplitter::Split(str1, sub_str_list1);
	StringSplitter::Split(str2, sub_str_list2);

	return StringComparer::Compare(sub_str_list1, sub_str_list2);
}
