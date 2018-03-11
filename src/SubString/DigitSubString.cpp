#include "DigitSubString.h"

using namespace std;


DigitSubString::DigitSubString(string str)
{
	// 将数字串中的每个数字和字符，转成对应的数值的列表，并将前面的无效0过滤掉
	// 如数字串"001\A\A"，转成的列表为[1,65,65]
	ParseStringToNumberList(str);
}

DigitSubString::~DigitSubString()
{

}

ComparableSubString::SUBSTRING_TYPE DigitSubString::GetType() const
{
	return ComparableSubString::SUBSTRING_TYPE_NUMBER;
}

// 获取字符串形式的子串的值，以进行比较
// 对于纯数字的串，是数字的十进制形式的每一位数字组成的字符串，
// 比如数字串"001\A\A"，其数字值为 1*100+65*10+65=815，则此接口返回的字符串为"815",不含前面的无效0的个数
void DigitSubString::GetValue(string &value) const
{
	vector<unsigned int> decimal_digital_list;

	// 根据数值列表中的每一个数值，计算出实际的十进制值，并将十进制数的每一位数字存放到decimal_digital_list中
	// 如数值列表为[1,65,65]，则计算的十进制数值为1*100+65*10+65=815，那么decimal_digital_list内容为[8,1,5]
	CalculateDecimalDigitList(decimal_digital_list);

	// 将十进制的每位数字组成的列表，转成一个字符串以返回
	// 如十进制数字列表内容[8,1,5]转成的字符串为"815"
	for (vector<unsigned int>::const_iterator it = decimal_digital_list.begin();
		 it != decimal_digital_list.end();
		 it++)
	{
		value += '0' + (*it);
	}
}

size_t DigitSubString::GetLength() const
{
	return _valid_number_list.size() + _prefix_zero_count;
}

// 将数字串中的每个数字和字符，转成对应的数值的列表，并将前面的无效0过滤掉
// 如数字串"001\A\A"，转成的列表为[1,65,65]
void DigitSubString::ParseStringToNumberList(const string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			AppendNumberToList(str[i] - '0');
		}
		else
		{
			AppendNumberToList(str[i]);
		}
	}
}

void DigitSubString::AppendNumberToList(unsigned int digit)
{
	if (_valid_number_list.size() > 0)
	{
		_valid_number_list.push_back(digit);
		return;
	}

	if (digit > 0)
	{
		_valid_number_list.push_back(digit);
	}
	else
	{
		_prefix_zero_count++;
	}
	
}

void DigitSubString::CalculateDecimalDigitList(vector<unsigned int> &decimal_digital_list) const
{
	vector<unsigned int>::const_iterator it;

	for (it = _valid_number_list.begin(); it != _valid_number_list.end(); it++)
	{
		AddNumberToDecimalDigitList(decimal_digital_list, *it);
	}
}

void DigitSubString::AddNumberToDecimalDigitList(vector<unsigned int> &decimal_digital_list, unsigned int digit) const
{
	unsigned int carry_bit = 0;
	unsigned int quotient = digit;
	unsigned int remainder;

	decimal_digital_list.push_back(0);

	vector<unsigned int>::reverse_iterator it_adder = decimal_digital_list.rbegin();

	do
	{
		remainder = quotient % 10;
		
		if (it_adder == decimal_digital_list.rend())
		{
			decimal_digital_list.insert(decimal_digital_list.begin(), 0);
			it_adder = decimal_digital_list.rend() - 1;
		}

		unsigned int sum = (*it_adder) + remainder + carry_bit;
		if (sum > 10)
		{
			(*it_adder) = sum - 10;
			carry_bit = 1;
		}
		else
		{
			(*it_adder) = sum;
			carry_bit = 0;
		}

		quotient = quotient / 10;
		it_adder++;
	} while (quotient > 0 || carry_bit > 0);
	
}

