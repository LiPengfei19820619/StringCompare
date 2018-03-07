#include "StringSplitter.h"

#include "CharSubString.h"
#include "DigitSubString.h"

ComparableSubString *StringSplitter::Split(const std::string &str)
{
	if (str.length() == 0)
	{
		return NULL;
	}

	if (isalpha(str[0]))
	{
		CharSubString *sub = new CharSubString();
		sub->Scan(str);
		return sub;
	}
	if (isdigit(str[0]))
	{
		DigitSubString *sub = new DigitSubString();
		sub->Scan(str);
		return sub;
	}

	return NULL;
}