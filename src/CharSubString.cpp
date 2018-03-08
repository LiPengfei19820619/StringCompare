#include "CharSubString.h"

void CharSubString::Scan(const std::string &str, size_t begin_index, size_t &end_index)
{
	size_t index = 0;

	for (index = begin_index; index < str.length(); index++)
	{
		if (!isalpha(str[index]))
		{
			break;
		}
		_value += str[index];
	}

	end_index = index;
}

int CharSubString::Compare(const ComparableSubString &substr)
{
	const CharSubString &csubstr = dynamic_cast<const CharSubString &>(substr);
	return strcmp(_value.c_str(), csubstr._value.c_str());
}