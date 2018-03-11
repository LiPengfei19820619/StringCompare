#include "DigitSubString.h"

DigitSubString::DigitSubString(std::string str)
{
	ParseStringToNumberList(str);
}

ComparableSubString::SUBSTRING_TYPE DigitSubString::GetType() const
{
	return ComparableSubString::SUBSTRING_TYPE_NUMBER;
}

void DigitSubString::GetValue(std::string &value) const
{
	std::vector<unsigned int> decimal_digital_list;

	CalculateDecimalDigitList(decimal_digital_list);

	for (std::vector<unsigned int>::const_iterator it = decimal_digital_list.begin();
		 it != decimal_digital_list.end();
		 it++)
	{
		value += '0' + (*it);
	}
}

size_t DigitSubString::GetLength() const
{
	return _digit_list.size() + _prefix_zero_count;
}

void DigitSubString::ParseStringToNumberList(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			AppendDigitToValue(str[i] - '0');
		}
		else
		{
			AppendDigitToValue(str[i]);
		}
	}
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

