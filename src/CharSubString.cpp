#include "CharSubString.h"

void CharSubString::Scan(const std::string &str)
{
	for (size_t index = 0; index < str.length(); index++)
	{
		if (!isalpha(str[index]))
		{
			return;
		}
		_value += str[index];
	}
}

int CharSubString::Compare(const ComparableSubString &substr)
{
	const CharSubString &csubstr = dynamic_cast<const CharSubString &>(substr);
	return strcmp(_value.c_str(), csubstr._value.c_str());
}