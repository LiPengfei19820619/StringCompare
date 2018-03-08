#include "CharSubString.h"

void CharSubString::Scan(const std::string &str, size_t begin_index, size_t &end_index)
{
	size_t index = 0;
	bool escape = false;
	int has_escaped_len = 0;

	for (index = begin_index; index < str.length(); index++)
	{
		if (!escape)
		{
			if (str[index] == '\\')
			{
				escape = true;
				has_escaped_len = 0;
			}
			else if (isalpha(str[index]))
			{
				_value += str[index];
			}
			else
			{
				break;
			}
		}
		else
		{			
			if (isdigit(str[index]))
			{
				_value += str[index];
				has_escaped_len++;
				if (has_escaped_len == 3)
				{
					escape = false;
					has_escaped_len = 0;
				}
			}
			else if (isalpha(str[index]))
			{
				if (has_escaped_len > 0)
				{
					_value += str[index];

					escape = false;
					has_escaped_len = 0;
				}
				else
				{
					index--;
					break;
				}
			}
			else if (str[index] == '\\')
			{
				if (has_escaped_len > 0)
				{
					escape = false;
					has_escaped_len = 0;
				}
				else
				{
					index--;
					break;
				}
			}
			else
			{
				break;
			}
		}
		
	}

	end_index = index;
}

int CharSubString::Compare(const ComparableSubString &substr)
{
	if (substr.IsDigitString())
	{
		return 1;
	}

	const CharSubString &csubstr = dynamic_cast<const CharSubString &>(substr);
	return strcmp(_value.c_str(), csubstr._value.c_str());
}

bool CharSubString::IsCharString() const
{
	return true;
}

bool CharSubString::IsDigitString() const
{
	return false;
}