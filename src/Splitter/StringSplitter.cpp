#include "StringSplitter.h"

#include "substring/CharSubString.h"
#include "substring/DigitSubString.h"

bool StringSplitter::Split(const std::string &str, std::vector<ComparableSubString *> &substrs)
{
	size_t cur_pos = 0;

	while (cur_pos < str.length())
	{
		ComparableSubString *sub = SplitASubString(str, cur_pos);
		if (sub == NULL)
		{
			break;
		}

		substrs.push_back(sub);
	}

	if (cur_pos < str.length())
	{
		return false;
	}
	return true;
}

ComparableSubString *StringSplitter::SplitASubString(const std::string &str, size_t &cur_pos)
{
	ComparableSubString *compSubString = NULL;
	std::string subString;

	if (CurrentPosIsChar(str, cur_pos))
	{
		subString = SplitACharSubString(str, cur_pos);

		compSubString = new CharSubString(subString);

		return compSubString;
	}
	if (CurrentPosIsDigit(str, cur_pos))
	{
		subString = SplitADigitSubString(str, cur_pos);

		compSubString = new DigitSubString(subString);

		return compSubString;
	}

	return NULL;
}

bool StringSplitter::CurrentPosIsChar(const std::string &str, size_t begin_pos)
{
	if (isalpha(str[begin_pos]))
	{
		return true;
	}

	if (IsEscapeChar(str[begin_pos]))
	{
		size_t next_index = begin_pos + 1;
		if (isdigit(str[next_index]))
		{
			return true;
		}
	}

	return false;
}

bool StringSplitter::CurrentPosIsDigit(const std::string &str, size_t begin_pos)
{
	if (isdigit(str[begin_pos]))
	{
		return true;
	}

	if (IsEscapeChar(str[begin_pos]))
	{
		size_t next_index = begin_pos + 1;
		if (isalpha(str[next_index]))
		{
			return true;
		}
	}

	return false;
}

bool StringSplitter::IsEscapeChar(char ch)
{
	return ch == '\\';
}

std::string StringSplitter::SplitACharSubString(const std::string &str, size_t &cur_pos)
{
	std::string subStr;
		
	while (CurrentPosIsChar(str, cur_pos))
	{
		if (isalpha(str[cur_pos]))
		{
			subStr += str[cur_pos];
			cur_pos++;
		}
		else if (IsEscapeChar(str[cur_pos]))
		{
			cur_pos++;
			int escapedLen = 0;
			while (isdigit(str[cur_pos]))
			{
				subStr += str[cur_pos];
				cur_pos++;
				escapedLen++;
				if (escapedLen == 3)
				{
					break;
				}
			}
		}
		else
		{

		}
	}

	return subStr;
}

std::string StringSplitter::SplitADigitSubString(const std::string &str, size_t &cur_pos)
{
	std::string subStr;
	
	while (CurrentPosIsDigit(str, cur_pos))
	{
		if (isdigit(str[cur_pos]))
		{
			subStr += str[cur_pos];
			cur_pos++;
		}
		else if (IsEscapeChar(str[cur_pos]))
		{
			cur_pos++;
			if (isalpha(str[cur_pos]))
			{
				subStr += str[cur_pos];
				cur_pos++;
			}
		}
		else
		{

		}
	}

	return subStr;
}