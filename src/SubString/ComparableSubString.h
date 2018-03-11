#pragma once

#include <vector>

class ComparableSubString
{
public:
	typedef enum
	{
		SUBSTRING_TYPE_CHAR = 0,
		SUBSTRING_TYPE_NUMBER = 1
	}SUBSTRING_TYPE;

	virtual ~ComparableSubString() {}

	virtual SUBSTRING_TYPE GetType() const = 0;

	// 获取字符串形式的子串的值，以进行比较
	// 对于纯字母的串，就是各字母组成的字符串
	// 对于纯数字的串，是数字的十进制形式的每一位数字组成的字符串，
	// 比如数字串"001\A\A"，其数字值为 1*100+65*10+65=815，则此接口返回的字符串为"815",不含前面的无效0的个数
	virtual void GetValue(std::string &value) const = 0;

	// 获取子串的长度
	// 对于数字串"001\A\A"，返回的长度为5
	virtual size_t GetLength() const = 0;
};