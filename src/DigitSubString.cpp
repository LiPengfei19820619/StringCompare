#include "DigitSubString.h"

void DigitSubString::Scan(const std::string &str, size_t begin_index, size_t &end_index)
{
	size_t index = 0;
	bool begin_valid_digit = false;

	for (index = begin_index; index < str.length(); index++)
	{
		if (!isdigit(str[index]))
		{
			break;
		}
		_digit_list.push_back(str[index] - '0');

		if (begin_valid_digit)
		{
			_valid_digit_count++;
		}
		else
		{
			if (str[index] != '0')
			{
				begin_valid_digit = true;
				_valid_digit_count++;
			}
		}
	}

	end_index = index;
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

