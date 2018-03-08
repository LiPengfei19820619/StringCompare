#include "StringSplitter.h"

#include "CharSubString.h"
#include "DigitSubString.h"

bool StringSplitter::Split(const std::string &str, std::vector<ComparableSubString *> &substrs)
{
	size_t cur_index = 0;

	while (cur_index < str.length())
	{
		ComparableSubString *sub = SplitASubString(str, cur_index, cur_index);
		if (sub == NULL)
		{
			break;
		}

		substrs.push_back(sub);
	}

	if (cur_index < str.length())
	{
		return false;
	}
	return true;
}

ComparableSubString *StringSplitter::SplitASubString(const std::string &str, size_t begin_pos, size_t &end_pos)
{
	if (isalpha(str[begin_pos]))
	{
		CharSubString *sub = new CharSubString();
		sub->Scan(str, begin_pos, end_pos);
		return sub;
	}
	else if (isdigit(str[begin_pos]))
	{
		DigitSubString *sub = new DigitSubString();
		sub->Scan(str, begin_pos, end_pos);
		return sub;
	}
	else if (IsEscapeChar(str[begin_pos]))
	{
		size_t next_index = begin_pos + 1;
		if (isalpha(str[next_index]))
		{
			DigitSubString *sub = new DigitSubString();
			sub->Scan(str, begin_pos, end_pos);
			return sub;
		}
		else if (isdigit(str[next_index]))
		{
			CharSubString *sub = new CharSubString();
			sub->Scan(str, begin_pos, end_pos);
			return sub;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

bool StringSplitter::IsEscapeChar(char ch)
{
	return ch == '\\';
}