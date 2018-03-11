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

	// ��ȡ�ַ�����ʽ���Ӵ���ֵ���Խ��бȽ�
	// ���ڴ���ĸ�Ĵ������Ǹ���ĸ��ɵ��ַ���
	// ���ڴ����ֵĴ��������ֵ�ʮ������ʽ��ÿһλ������ɵ��ַ�����
	// �������ִ�"001\A\A"��������ֵΪ 1*100+65*10+65=815����˽ӿڷ��ص��ַ���Ϊ"815",����ǰ�����Ч0�ĸ���
	virtual void GetValue(std::string &value) const = 0;

	// ��ȡ�Ӵ��ĳ���
	// �������ִ�"001\A\A"�����صĳ���Ϊ5
	virtual size_t GetLength() const = 0;
};