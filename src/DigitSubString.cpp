#include "DigitSubString.h"

void DigitSubString::Scan(const std::string &str, size_t begin_index, size_t &end_index)
{
	size_t index = begin_index;

	while (index < str.length())
	{
		if (!Append(str, index, end_index))
		{
			return;
		}

		index = end_index;
	}

	return;
}

int DigitSubString::Compare(const ComparableSubString &substr)
{
	if (substr.IsCharString())
	{
		return -1;
	}

	const DigitSubString digit_sub_str = dynamic_cast<const DigitSubString &>(substr);

	return DoCompare(digit_sub_str);
}

bool DigitSubString::IsCharString() const
{
	return false;
}

bool DigitSubString::IsDigitString() const
{
	return true;
}

bool DigitSubString::Append(const std::string &str, size_t cur_index, size_t &next_index)
{
	next_index = cur_index + 1;

	if (!_is_escape)
	{
		return AppendNonEscapeChar(str, cur_index, next_index);
	}
	else
	{
		return AppendEscapeChar(str, cur_index, next_index);
	}
}

bool DigitSubString::AppendNonEscapeChar(const std::string &str, size_t cur_index, size_t &next_index)
{
	next_index = cur_index + 1;

	if (isdigit(str[cur_index]))
	{
		AppendDigitToValue(str[cur_index] - '0');
	}
	else if (str[cur_index] == '\\')
	{
		if (!isalpha(str[next_index]))
		{
			next_index = cur_index;
			return false;
		}
		_is_escape = true;
	}
	else
	{
		next_index = cur_index;
		return false;
	}

	return true;
}

bool DigitSubString::AppendEscapeChar(const std::string &str, size_t cur_index, size_t &next_index)
{
	next_index = cur_index + 1;

	if (isalpha(str[cur_index]))
	{
		AppendDigitToValue(str[cur_index]);

		_is_escape = false;
	}
	else
	{
		next_index = cur_index;
		return false;
	}

	return true;
}

void DigitSubString::AppendDigitToValue(unsigned int digit)
{
	if (_digit_list.size() > 0)
	{
		_digit_list.push_back(digit);
		return;
	}

	if (digit > 0)
	{
		_digit_list.push_back(digit);
	}
	else
	{
		_prefix_zero_count++;
	}
	
}

int DigitSubString::DoCompare(const DigitSubString &digit_sub_str) const
{
	int result = 0;

	result = DoCompareValue(digit_sub_str);
	if (result != 0)
	{
		return result;
	}

	return DoCompareLength(digit_sub_str);
}

int DigitSubString::DoCompareValue(const DigitSubString &digit_sub_str) const
{
	int result = 0;
	std::vector<unsigned int> decimal_digital_list_1;
	std::vector<unsigned int> decimal_digital_list_2;

	CalculateDecimalDigitList(decimal_digital_list_1);
	digit_sub_str.CalculateDecimalDigitList(decimal_digital_list_2);

	result = DoCompareValueByValidDigitCount(decimal_digital_list_1, decimal_digital_list_2);
	if (result != 0)
	{
		return result;
	}
	
	return DoCompareValueByEachValidDigit(decimal_digital_list_1, decimal_digital_list_2);
}

int DigitSubString::DoCompareLength(const DigitSubString &digit_sub_str) const
{
	if (_digit_list.size() + _prefix_zero_count > digit_sub_str._digit_list.size() + digit_sub_str._prefix_zero_count)
	{
		return 1;
	}
	if (_digit_list.size() + _prefix_zero_count < digit_sub_str._digit_list.size() + digit_sub_str._prefix_zero_count)
	{
		return -1;
	}

	return 0;
}

int DigitSubString::DoCompareValueByValidDigitCount(std::vector<unsigned int> &decimal_digital_list_1,
													std::vector<unsigned int> &decimal_digital_list_2) const
{
	if (decimal_digital_list_1.size() > decimal_digital_list_2.size())
	{
		return 1;
	}
	else if (decimal_digital_list_1.size() < decimal_digital_list_2.size())
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int DigitSubString::DoCompareValueByEachValidDigit(std::vector<unsigned int> &decimal_digital_list_1,
												   std::vector<unsigned int> &decimal_digital_list_2) const
{
	std::vector<unsigned int>::const_iterator it1 = decimal_digital_list_1.begin();
	std::vector<unsigned int>::const_iterator it2 = decimal_digital_list_2.begin();

	for (; it1 != decimal_digital_list_1.end(); it1++, it2++)
	{
		if ((*it1) > (*it2))
		{
			return 1;
		}
		else if ((*it1) < (*it2))
		{
			return -1;
		}
		else
		{

		}
	}

	return 0;
}

void DigitSubString::CalculateDecimalDigitList(std::vector<unsigned int> &decimal_digital_list) const
{
	std::vector<unsigned int>::const_iterator it;

	for (it = _digit_list.begin(); it != _digit_list.end(); it++)
	{
		AddtoDecimalDigitList(decimal_digital_list, *it);
	}
}

void DigitSubString::AddtoDecimalDigitList(std::vector<unsigned int> &decimal_digital_list, unsigned int digit) const
{
	unsigned int carry_bit = 0;
	unsigned int quotient = digit;
	unsigned int remainder;

	decimal_digital_list.push_back(0);

	std::vector<unsigned int>::reverse_iterator it_adder = decimal_digital_list.rbegin();

	do
	{
		remainder = quotient % 10;
		
		if (it_adder == decimal_digital_list.rend())
		{
			decimal_digital_list.insert(decimal_digital_list.begin(), 0);
			it_adder = decimal_digital_list.rend() - 1;
		}

		unsigned int sum = (*it_adder) + remainder + carry_bit;
		if (sum > 10)
		{
			(*it_adder) = sum - 10;
			carry_bit = 1;
		}
		else
		{
			(*it_adder) = sum;
			carry_bit = 0;
		}

		quotient = quotient / 10;
		it_adder++;
	} while (quotient > 0 || carry_bit > 0);
	
}

