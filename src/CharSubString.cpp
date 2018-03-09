#include "CharSubString.h"

void CharSubString::Scan(const std::string &str, size_t begin_index, size_t &end_index)
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

bool CharSubString::Append(const std::string &str, size_t cur_index, size_t &next_index)
{
	if (!_is_escape)
	{
		return AppendNonEscapeChar(str, cur_index, next_index);
	}
	else
	{
		return AppendEscapeChar(str, cur_index, next_index);
	}
}

bool CharSubString::AppendNonEscapeChar(const std::string &str, size_t cur_index, size_t &next_index)
{
	char ch = str[cur_index];
	next_index = cur_index + 1;

	if (ch == '\\')
	{
		StartEscape();
	}
	else if (isalpha(ch))
	{
		_value += ch;
	}
	else
	{
		next_index = cur_index;
		return  false;
	}

	return true;
}

bool CharSubString::AppendEscapeChar(const std::string &str, size_t cur_index, size_t &next_index)
{
	if (_has_escaped_len == 0)
	{
		return BeginAppendEscapeChar(str, cur_index, next_index);
	}
	else
	{
		return ContinueAppendEscapeChar(str, cur_index, next_index);
	}
}

bool CharSubString::BeginAppendEscapeChar(const std::string &str, size_t cur_index, size_t &next_index)
{
	char ch = str[cur_index];
	next_index = cur_index + 1;

	if (isdigit(ch))
	{
		_value += ch;

		_has_escaped_len++;
	}
	else
	{
		next_index = cur_index;
		return false;
	}

	return true;
}

bool CharSubString::ContinueAppendEscapeChar(const std::string &str, size_t cur_index, size_t &next_index)
{
	char ch = str[cur_index];
	next_index = cur_index + 1;

	if (isdigit(ch))
	{
		_value += ch;

		_has_escaped_len++;
		if (HasReachMaxEscapeLen())
		{
			EndEscape();
		}
	}
	else
	{
		EndEscape();
		next_index = cur_index;
	}
	
	return true;
}

void CharSubString::StartEscape()
{
	_is_escape = true;
	_has_escaped_len = 0;
}

void CharSubString::EndEscape()
{
	_is_escape = false;
	_has_escaped_len = 0;
}

bool CharSubString::HasReachMaxEscapeLen() const
{
	return _has_escaped_len >= MAX_ESCAPE_LEN;
}