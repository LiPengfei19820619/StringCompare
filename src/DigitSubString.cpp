#include "DigitSubString.h"

void DigitSubString::Scan(const std::string &str)
{
	for (size_t index = 0; index < str.length(); index++)
	{
		if (!isdigit(str[index]))
		{
			return;
		}
		_digit_list.push_back(str[index] - '0');
	}
}

int DigitSubString::Compare(const ComparableSubString &substr)
{
	const DigitSubString dsubstr = dynamic_cast<const DigitSubString &>(substr);

	unsigned int self_value = GetValue();
	unsigned int value = dsubstr.GetValue();

	if (self_value > value)
	{
		return 1;
	}
	else if (self_value < value)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

unsigned int DigitSubString::GetValue() const
{
	unsigned int value = 0;

	std::vector<unsigned int>::const_iterator it;
	for (it = _digit_list.begin(); it != _digit_list.end(); it++)
	{
		value += (*it) * 10;
	}

	return value;
}