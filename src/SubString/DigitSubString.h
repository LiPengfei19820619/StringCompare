#pragma once

#include "ComparableSubString.h"
#include <vector>
#include <string>

class DigitSubString : public ComparableSubString
{
public:
	DigitSubString(std::string str);

	SUBSTRING_TYPE GetType() const;

	void GetValue(std::string &value) const;
	virtual size_t GetLength() const;
	
private:
	void ParseStringToNumberList(const std::string str);

	void AppendDigitToValue(unsigned int digit);

	void CalculateDecimalDigitList(std::vector<unsigned int> &decimal_digital_list) const;
	void AddtoDecimalDigitList(std::vector<unsigned int> &decimal_digital_list, unsigned int digit) const;

	std::vector<unsigned int> _digit_list;
	int _prefix_zero_count;
};