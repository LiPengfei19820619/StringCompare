#include "StringSplitter.h"

#include "substring/CharSubString.h"
#include "substring/DigitSubString.h"

using namespace std;


// 从字符串str自左到右依次拆分出所有的子串（纯字符串、纯数字串）
bool StringSplitter::Split(const string &str, vector<ComparableSubString *> &substrs)
{
	size_t cur_pos = 0;

	while (cur_pos < str.length())
	{
		// 从str的当前位置cur_pos拆分出一个子串出来，拆分后cur_pos指向下一个子串的开始位置
		ComparableSubString *sub = SplitASubString(str, cur_pos);
		if (sub == NULL)
		{
			break;
		}

		substrs.push_back(sub);
	}

	// 未到字符串末尾就拆分结束，说明遇到非法字符导致拆分失败了
	if (cur_pos < str.length())
	{
		return false;
	}
	return true;
}

ComparableSubString *StringSplitter::SplitASubString(const string &str, size_t &cur_pos)
{
	ComparableSubString *compSubString = NULL;
	string subString;

	if (CurrentPosIsChar(str, cur_pos))
	{
		// 拆分出一个纯字母的子串
		subString = SplitACharSubString(str, cur_pos);

		compSubString = new CharSubString(subString);

		return compSubString;
	}
	if (CurrentPosIsDigit(str, cur_pos))
	{
		// 拆分出一个纯数字的子串
		subString = SplitADigitSubString(str, cur_pos);

		compSubString = new DigitSubString(subString);

		return compSubString;
	}

	return NULL;
}

string StringSplitter::SplitACharSubString(const string &str, size_t &cur_pos)
{
	string subStr;

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

			subStr += GetAllEscapedCharForCharSubString(str, cur_pos);
		}
		else
		{

		}
	}

	return subStr;
}

string StringSplitter::SplitADigitSubString(const string &str, size_t &cur_pos)
{
	string subStr;

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

string StringSplitter::GetAllEscapedCharForCharSubString(const string &str, size_t &cur_pos)
{
	string escaped_chars;

	int escapedLen = 0;

	while (isdigit(str[cur_pos]))
	{
		escaped_chars += str[cur_pos];
		cur_pos++;

		escapedLen++;
		if (ReachMaxEscapeCharNum(escapedLen))
		{
			break;
		}
	}

	return escaped_chars;
}

bool StringSplitter::ReachMaxEscapeCharNum(int escaped_len)
{
	return escaped_len >= MAX_ESCAPE_CHAR_NUM;
}

bool StringSplitter::CurrentPosIsChar(const string &str, size_t begin_pos)
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

bool StringSplitter::CurrentPosIsDigit(const string &str, size_t begin_pos)
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

