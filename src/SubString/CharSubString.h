#pragma once

#include "ComparableSubString.h"
#include <string>

class CharSubString : public ComparableSubString
{
public:
	CharSubString(std::string str);

	SUBSTRING_TYPE GetType() const;

	void GetValue(std::string &value) const;
	virtual size_t GetLength() const;

private:
	std::string _value;
};
