#pragma once

class ComparableSubString
{
public:
	virtual int Compare(const ComparableSubString &substr) = 0;
};