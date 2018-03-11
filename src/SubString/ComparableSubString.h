#pragma once

#include <vector>

class ComparableSubString
{
public:
	typedef enum
	{
		SUBSTRING_TYPE_CHAR = 0,
		SUBSTRING_TYPE_NUMBER = 1
	}SUBSTRING_TYPE;

	virtual SUBSTRING_TYPE GetType() const = 0;

	virtual void GetValue(std::string &value) const = 0;
	virtual size_t GetLength() const = 0;
};