#pragma once

#include "ComparableSubString.h"
#include <vector>
#include <string>

class DigitSubString : public ComparableSubString
{
public:
	void Scan(const std::string &str, size_t begin_index, size_t &end_index);
	int Compare(const ComparableSubString &substr);
	unsigned int GetValue() const;

private:
	std::vector<unsigned int> _digit_list;
};