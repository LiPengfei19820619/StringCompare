#pragma once

#include "ComparableSubString.h"
#include <string>

class CharSubString : public ComparableSubString
{
public:
	void Scan(const std::string &str, size_t begin_index, size_t &end_index);
	int Compare(const ComparableSubString &substr);

private:
	std::string _value;
};