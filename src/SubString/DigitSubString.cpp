#include "DigitSubString.h"

using namespace std;


DigitSubString::DigitSubString(string str)
{
	// �����ִ��е�ÿ�����ֺ��ַ���ת�ɶ�Ӧ����ֵ���б�����ǰ�����Ч0���˵�
	// �����ִ�"001\A\A"��ת�ɵ��б�Ϊ[1,65,65]
	ParseStringToNumberList(str);
}

DigitSubString::~DigitSubString()
{

}

ComparableSubString::SUBSTRING_TYPE DigitSubString::GetType() const
{
	return ComparableSubString::SUBSTRING_TYPE_NUMBER;
}

// ��ȡ�ַ�����ʽ���Ӵ���ֵ���Խ��бȽ�
// ���ڴ����ֵĴ��������ֵ�ʮ������ʽ��ÿһλ������ɵ��ַ�����
// �������ִ�"001\A\A"��������ֵΪ 1*100+65*10+65=815����˽ӿڷ��ص��ַ���Ϊ"815",����ǰ�����Ч0�ĸ���
void DigitSubString::GetValue(string &value) const
{
	vector<unsigned int> decimal_digital_list;

	// ������ֵ�б��е�ÿһ����ֵ�������ʵ�ʵ�ʮ����ֵ������ʮ��������ÿһλ���ִ�ŵ�decimal_digital_list��
	// ����ֵ�б�Ϊ[1,65,65]��������ʮ������ֵΪ1*100+65*10+65=815����ôdecimal_digital_list����Ϊ[8,1,5]
	CalculateDecimalDigitList(decimal_digital_list);

	// ��ʮ���Ƶ�ÿλ������ɵ��б�ת��һ���ַ����Է���
	// ��ʮ���������б�����[8,1,5]ת�ɵ��ַ���Ϊ"815"
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

// �����ִ��е�ÿ�����ֺ��ַ���ת�ɶ�Ӧ����ֵ���б�����ǰ�����Ч0���˵�
// �����ִ�"001\A\A"��ת�ɵ��б�Ϊ[1,65,65]
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

