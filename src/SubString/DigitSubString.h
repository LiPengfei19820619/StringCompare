#pragma once

#include "ComparableSubString.h"
#include <vector>
#include <string>

class DigitSubString : public ComparableSubString
{
public:
	DigitSubString(std::string str);
	~DigitSubString();

	SUBSTRING_TYPE GetType() const;

	void GetValue(std::string &value) const;
	virtual size_t GetLength() const;
	
private:
	void ParseStringToNumberList(const std::string str);

	void AppendNumberToList(unsigned int digit);

	void CalculateDecimalDigitList(std::vector<unsigned int> &decimal_digital_list) const;
	void AddNumberToDecimalDigitList(std::vector<unsigned int> &decimal_digital_list, unsigned int digit) const;

	// 将数字串中的每个数字和字符，转成对应的数值的列表，并将前面的无效0过滤掉
	// 如数字串"001\A\A"，转成的列表为[1,65,65]
	std::vector<unsigned int> _valid_number_list;

	int _prefix_zero_count;
};