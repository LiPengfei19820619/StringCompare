#pragma once

class ComparableSubString
{
public:
	virtual int Compare(const ComparableSubString &substr) = 0;
	virtual bool IsCharString() const = 0;
	virtual bool IsDigitString() const = 0;
};