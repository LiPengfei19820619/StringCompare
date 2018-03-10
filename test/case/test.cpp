#include "StringCompare.h"

#include "gtest/gtest.h"


// �������ַ����ַ����Ƚ�
TEST(StringCompare, GIVEN_Two_Strings_With_Only_Chars_WHEN_Compare_THEN_Strcmp)
{
	EXPECT_EQ(StringCompare("abc", "abd"), -1);
}

// ���������ֵ��ַ����Ƚ�
TEST(StringCompare, GIVEN_Two_Strings_With_Only_Digits_WHEN_Compare_THEN_CompareWithNumber)
{
	EXPECT_EQ(StringCompare("92", "256"), -1);
	EXPECT_EQ(StringCompare("1234", "1234"), 0);
	EXPECT_EQ(StringCompare("01234", "1234"), 1);
	EXPECT_EQ(StringCompare("01234", "12034"), -1);
	EXPECT_EQ(StringCompare("01234", "12340"), -1);
	EXPECT_EQ(StringCompare("0001234", "0001234"), 0);
	EXPECT_EQ(StringCompare("00000", "0000"), 1);

	EXPECT_EQ(StringCompare("000000001234", "00000001234"), 1);
	EXPECT_EQ(StringCompare("00000001234", "000000001234"), -1);

	EXPECT_EQ(StringCompare("123456789012345678901234567890", "123456789012345678901234567890"), 0);
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "00000123456789012345678901234567890"), 0);
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "0000123456789012345678901234567890"), 1);
	EXPECT_EQ(StringCompare("0000123456789012345678901234567890", "00000123456789012345678901234567890"), -1);

	EXPECT_EQ(StringCompare("123456789012345678901234567895", "123456789012345678901234567890"), 1);
	EXPECT_EQ(StringCompare("123456789012345678901234567895", "123456789012345678901234567898"), -1);
}

// �����ַ����ֻ�ϵ��ַ���(�ַ��Ӵ��������Ӵ���Ӧ)�Ƚ�
TEST(StringCompare, GIVEN_Two_Strings_With_Digits_And_Chars_InSamePosition_WHEN_Compare_THEN_GetResult)
{
	EXPECT_EQ(StringCompare("abc123", "abd90"), -1);
	EXPECT_EQ(StringCompare("abc123", "abc90"), 1);

	EXPECT_EQ(StringCompare("abc123", "abc123"), 0);

	EXPECT_EQ(StringCompare("abc123", "abc"), 1);
	EXPECT_EQ(StringCompare("abc", "abc123"), -1);

	EXPECT_EQ(StringCompare("abc123def", "abc123deg"), -1);
	EXPECT_EQ(StringCompare("abc123def", "abc123def"), 0);
	EXPECT_EQ(StringCompare("abc123def", "abc124def"), -1);
	EXPECT_EQ(StringCompare("abc1230def", "abc124def"), 1);
	EXPECT_EQ(StringCompare("abc1230def", "abc01230def"), -1);
	EXPECT_EQ(StringCompare("abc1230", "abc124def"), 1);
}

// ���ַ��Ĵ��ʹ����ֵĴ����бȽ�(����(3)������Ƚϵ�һ���������ִ���һ��������ĸ�����������ִ�С��)
TEST(StringCompare, GIVEN_String1_PureChars_String2_PureDigits_WHEN_Compare_THEN_String1_BiggerThan_String2)
{
	EXPECT_EQ(StringCompare("abc", "90"), 1);
	EXPECT_EQ(StringCompare("abcdefghijklmnopqrstuvwxyz", "01234567890123456789012345678901234567890123456789"), 1);
}

// �����ֵĴ��ʹ���ĸ�Ĵ����бȽ�(����(3)������Ƚϵ�һ���������ִ���һ��������ĸ�����������ִ�С��)
TEST(StringCompare, GIVEN_String1_PureDigits_String2_PureAlphabets_WHEN_Compare_THEN_String1_LittleThan_String2)
{
	EXPECT_EQ(StringCompare("90", "abc"), -1);
	EXPECT_EQ(StringCompare("01234567890123456789012345678901234567890123456789", "abcdefghijklmnopqrstuvwxyz"), -1);
}

// �����ַ����ֻ�ϵ��ַ���(�ַ��Ӵ��������Ӵ�����Ӧ)�Ƚ�
TEST(StringCompare, GIVEN_Two_Strings_With_Digits_And_Chars_NotInSamePosition_WHEN_Compare_THEN_GetResult)
{
	EXPECT_EQ(StringCompare("90abc", "abc90"), -1);
}

// �ַ���1����������ת��Ϊ�ַ����ַ���2����������ĸ
TEST(StringCompare, GIVEN_String1_DigitEscapeToChar_String2_PureAlphabet_WHEN_Compare_THEN_ResultSameWithStrcmp)
{
	EXPECT_EQ(StringCompare("abc\\1", "abcd"), -1);
	EXPECT_EQ(StringCompare("abc\\1", "abc"), 1);
	EXPECT_EQ(StringCompare("abc\\12", "abc"), 1);
	EXPECT_EQ(StringCompare("abc\\123", "abc"), 1);
	EXPECT_EQ(StringCompare("abc\\1234", "abc"), 1);
	EXPECT_EQ(StringCompare("abc\\1234", "abcdefg"), -1);
	EXPECT_EQ(StringCompare("abc\\1234\\123", "abcdefg"), -1);
	EXPECT_EQ(StringCompare("\\123abc", "abcd"), -1);
}

// �ַ���1��������ĸ��ת�����֡����֣��ַ���2��������ĸ��ת�����֡�����
TEST(StringCompare, GIVEN_String1_AlphabetEscapeDigit_String2_AlphabetDigit_WHEN_Compare_THEN_ResultSameWithStrcmp)
{
	EXPECT_EQ(StringCompare("abc\\123456789", "abc\\23456789"), -1);
	EXPECT_EQ(StringCompare("abc\\12\\3def", "abc\\123def"), 0);
}

// �ַ���1��������ĸ��ת����ĸ�����֣��ַ���2��������ĸ��ת����ĸ������
TEST(StringCompare, GIVEN_String1_AlphabetEscapeAlphabetDigit_String2_AlphabetEscapeAlphabetDigit_WHEN_Compare_THEN_ResultSameWithStrcmp)
{
	EXPECT_EQ(StringCompare("123\\a5", "12345"), 1);
	EXPECT_EQ(StringCompare("97", "\\a"), 1);
	EXPECT_EQ(StringCompare("65", "\\A"), 1);
	EXPECT_EQ(StringCompare("97", "0\\a"), 0);
	EXPECT_EQ(StringCompare("65", "0\\A"), 0);

	EXPECT_EQ(StringCompare("065", "0\\A"), 1);
}

// �ַ���1�������Ƿ��ַ����ַ���2��������ĸ��ת����ĸ�����֣����������-2
TEST(StringCompare, GIVEN_String1_InvalidChar_String2_AlphabetEscapeAlphabetDigit_WHEN_Compare_THEN_ReturnMinus2)
{
	EXPECT_EQ(StringCompare("123.5", "12345"), -2);
	EXPECT_EQ(StringCompare("12345\\", "12345"), -2);
}

