#include "CharSubString.h"


CharSubString::CharSubString(std::string str)
	: _value(str)
{

}

ComparableSubString::SUBSTRING_TYPE CharSubString::GetType() const
{
	return ComparableSubString::SUBSTRING_TYPE_CHAR;
}

void CharSubString::GetValue(std::string &value) const
{
	value = _value;
}

size_t CharSubString::GetLength() const
{
	return _value.size();
}



