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
	char ch = str[cur_index];
	next_index = cur_index + 1;

	if (!_is_escape)
	{
		if (ch == '\\')
		{
			_is_escape = true;
			_has_escaped_len = 0;
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
	}
	else
	{
		if (isdigit(ch))
		{
			_value += ch;

			_has_escaped_len++;
			if (_has_escaped_len == 3)
			{
				_is_escape = false;
				_has_escaped_len = 0;
			}
		}
		else if (isalpha(ch))
		{
			if (_has_escaped_len > 0)
			{
				_value += ch;

				_is_escape = false;
				_has_escaped_len = 0;
			}
			else
			{
				// 需要回退
				next_index = cur_index - 1;
				return false;
			}
		}
		else if (ch == '\\')
		{
			if (_has_escaped_len > 0)
			{
				
				_has_escaped_len = 0;
			}
			else
			{
				// 需要回退
				next_index = cur_index - 1;
				return false;
			}
		}
		else
		{
			next_index = cur_index;
			return false;
		}
	}
	return true;
}