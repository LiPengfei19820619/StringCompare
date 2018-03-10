#pragma once

#include "ComparableSubString.h"
#include <vector>
#include <string>

class DigitSubString : public ComparableSubString
{
public:
	void Scan(const std::string &str, size_t begin_index, size_t &end_index);

	int Compare(const ComparableSubString &substr);
	bool IsCharString() const;
	bool IsDigitString() const;
	
private:
	bool Append(const std::string &str, size_t cur_index, size_t &next_index);

	bool AppendNonEscapeChar(const std::string &str, size_t cur_index, size_t &next_index);
	bool AppendEscapeChar(const std::string &str, size_t cur_index, size_t &next_index);

	void AppendDigitToValue(unsigned int digit);

	int DoCompare(const DigitSubString &digit_sub_str) const;
	int DoCompareValue(const DigitSubString &digit_sub_str) const;
	int DoCompareLength(const DigitSubString &digit_sub_str) const;

	int DoCompareValueByValidDigitCount(const DigitSubString &digit_sub_str) const;
	int DoCompareValueByEachValidDigit(const DigitSubString &digit_sub_str) const;

	int DoCompareValueByValidDigitCount(std::vector<unsigned int> &decimal_digital_list_1,
										std::vector<unsigned int> &decimal_digital_list_2) const;
	int DoCompareValueByEachValidDigit(std::vector<unsigned int> &decimal_digital_list_1,
									   std::vector<unsigned int> &decimal_digital_list_2) const;

	void CalculateDecimalDigitList(std::vector<unsigned int> &decimal_digital_list) const;
	void AddtoDecimalDigitList(std::vector<unsigned int> &decimal_digital_list, unsigned int digit) const;

	std::vector<unsigned int> _digit_list;
	int _prefix_zero_count;

	bool _is_escape;
};