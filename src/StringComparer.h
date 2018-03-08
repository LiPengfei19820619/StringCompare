#pragma once

#include "ComparableSubString.h"
#include <vector>

class StringComparer
{
public:
	static int Compare(const std::vector<ComparableSubString *> &sub_str_list1,
					   const std::vector<ComparableSubString *> &sub_str_list2);
};