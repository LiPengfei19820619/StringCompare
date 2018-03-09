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

	const DigitSubString dsubstr = dynamic_cast<const DigitSubString &>(substr);

	if (_valid_digit_count > dsubstr._valid_digit_count)
	{
		return 1;
	}
	else if (_valid_digit_count < dsubstr._valid_digit_count)
	{
		return -1;
	}
	else
	{
		std::vector<unsigned int>::const_iterator it1 = _digit_list.begin();
		std::vector<unsigned int>::const_iterator it2 = dsubstr._digit_list.begin();

		for (; it1 != _digit_list.end(); it1++)
		{
			if (*it1 > 0)
			{
				break;
			}
		}
		for (; it2 != dsubstr._digit_list.end(); it2++)
		{
			if (*it2 > 0)
			{
				break;
			}
		}

		for (; it1 != _digit_list.end(); it1++,it2++)
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
	}

	if (_digit_list.size() > dsubstr._digit_list.size())
	{
		return 1;
	}
	if (_digit_list.size() < dsubstr._digit_list.size())
	{
		return -1;
	}
	return 0;

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
	_digit_list.push_back(digit);

	if (_valid_digit_count > 0)
	{
		_valid_digit_count++;
	}
	else
	{
		if (digit != 0)
		{
			_valid_digit_count++;
		}
	}
}

