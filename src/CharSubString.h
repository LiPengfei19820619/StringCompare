#pragma once

#include "ComparableSubString.h"
#include <string>

class CharSubString : public ComparableSubString
{
public:
	void Scan(const std::string &str);
	int Compare(const ComparableSubString &substr);

private:
	std::string _value;
};