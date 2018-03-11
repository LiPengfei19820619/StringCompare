#include "StringCompare.h"

#include "gtest/gtest.h"


// ---------- ��������ĸ���ַ����Ƚ�������ʼ

// �ַ���1������ĸ���ַ������ַ���2����������ĸ���ַ���������strcmp�����ַ���1С���ַ���2����ȽϽ��Ϊ-1
TEST(StringCompare, GIVEN_String1_WithOnlyAlphabetChars_String2_WithOnlyAlphabetChars_String1LittleThanString2_WHEN_StringCompare_THEN_Get_Little)
{
	EXPECT_EQ(StringCompare("abc", "abd"), -1);
	EXPECT_EQ(StringCompare("abc", "abcd"), -1);
	EXPECT_EQ(StringCompare("abc", "bcd"), -1);
	EXPECT_EQ(StringCompare("baby", "father"), -1);
	EXPECT_EQ(StringCompare("BABY", "FATHER"), -1);
}

// �ַ���1������ĸ���ַ������ַ���2����������ĸ���ַ���������strcmp�����ַ���1�������ַ���2����ȽϽ��Ϊ0
TEST(StringCompare, GIVEN_String1_WithOnlyAlphabetChars_String2_WithOnlyAlphabetChars_String1EqualToString2_WHEN_StringCompare_THEN_Get_Equal)
{
	EXPECT_EQ(StringCompare("abcdefg", "abcdefg"), 0);
}

// �ַ���1������ĸ���ַ������ַ���2����������ĸ���ַ���������strcmp�����ַ���1�����ַ���2����ȽϽ��Ϊ1
TEST(StringCompare, GIVEN_String1_WithOnlyAlphabetChars_String2_WithOnlyAlphabetChars_String1GreaterThanString2_WHEN_StringCompare_THEN_Get_Greater)
{
	EXPECT_EQ(StringCompare("bcdefg", "abcdefgh"), 1);
	EXPECT_EQ(StringCompare("bcdefghxyz", "bcdefgh"), 1);
	EXPECT_EQ(StringCompare("bcdxyz", "bcdefgh"), 1);
}


// ----------���������ֵ��ַ����Ƚ�������ʼ

// �ַ���1�������֣��ַ���2�������֣��ַ���1������ֵС���ַ���2������ֵ����ȽϽ��Ϊ-1
TEST(StringCompare, GIVEN_String1_WithOnlyDigits_String2_WithOnlyDigits_String1NumericValueLitter_WHEN_Compare_THEN_Get_Little)
{
	EXPECT_EQ(StringCompare("92", "256"), -1);
	EXPECT_EQ(StringCompare("902", "2560"), -1);
	EXPECT_EQ(StringCompare("902", "920"), -1);
	EXPECT_EQ(StringCompare("092", "256"), -1);
	EXPECT_EQ(StringCompare("92", "0256"), -1);
	EXPECT_EQ(StringCompare("00092", "00256"), -1);
}

// �ַ���1�������֣��ַ���2�������֣��ַ���1������ֵ�����ַ���2������ֵ����ȽϽ��Ϊ1
TEST(StringCompare, GIVEN_String1_WithOnlyDigits_String2_WithOnlyDigits_String1NumericValueGreater_WHEN_Compare_THEN_Get_Greater)
{
	EXPECT_EQ(StringCompare("492", "256"), 1);
	EXPECT_EQ(StringCompare("0492", "256"), 1);
	EXPECT_EQ(StringCompare("492", "0256"), 1);
	EXPECT_EQ(StringCompare("0492", "0256"), 1);
	EXPECT_EQ(StringCompare("0492", "000256"), 1);
}

// �ַ���1�������֣��ַ���2�������֣��ַ���1������ֵ�����ַ���2������ֵ����ȽϽ��Ϊ�Ӵ����Ľϴ�
TEST(StringCompare, GIVEN_String1_WithOnlyDigits_String2_WithOnlyDigits_String1NumericValueEqual_WHEN_Compare_THEN_LongerIsGreater)
{
	EXPECT_EQ(StringCompare("492", "492"), 0);
	EXPECT_EQ(StringCompare("0492", "492"), 1);
	EXPECT_EQ(StringCompare("492", "0492"), -1);
	EXPECT_EQ(StringCompare("0492", "0492"), 0);
	EXPECT_EQ(StringCompare("0492", "000492"), -1);
}

// �ַ���1�������Ĵ����֣��ַ���2�������Ĵ����֣��ַ���1������ֵС���ַ���2������ֵ����ȽϽ��Ϊ-1
TEST(StringCompare, GIVEN_String1_WithOnlyDigitsVeryLong_String2_WithOnlyDigitsVeryLong_String1NumericValueLitter_WHEN_Compare_THEN_Get_Little)
{
	EXPECT_EQ(StringCompare("123456789012345678901234567895", "123456789012345678901234567898"), -1);
}

// �ַ���1�������Ĵ����֣��ַ���2�������Ĵ����֣��ַ���1������ֵ�����ַ���2������ֵ����ȽϽ��Ϊ1
TEST(StringCompare, GIVEN_String1_WithOnlyDigitsVeryLong_String2_WithOnlyDigitsVeryLong_String1NumericValueGreater_WHEN_Compare_THEN_Get_Greater)
{
	EXPECT_EQ(StringCompare("123456789012345678901234567895", "123456789012345678901234567890"), 1);
}

// �ַ���1�������Ĵ����֣��ַ���2�������Ĵ����֣��ַ���1������ֵ�����ַ���2������ֵ����ȽϽ��Ϊ�Ӵ����Ľϴ�
TEST(StringCompare, GIVEN_String1_WithOnlyDigitsVeryLong_String2_WithOnlyDigitsVeryLong_String1NumericValueEqual_WHEN_Compare_THEN_LongerIsGreater)
{
	EXPECT_EQ(StringCompare("123456789012345678901234567890", "123456789012345678901234567890"), 0);

	// ǰ�涼��5��0
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "00000123456789012345678901234567890"), 0);

	// �ַ���1ǰ��5��0���ַ���2ǰ��4��0
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "0000123456789012345678901234567890"), 1);

	// �ַ���1ǰ��5��0���ַ���2ǰ��6��0
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "000000123456789012345678901234567890"), -1);
}


// -----------------�����ַ����ֻ�ϵ��ַ����Ƚ�

// �ַ���1����ĸ���ֻ�ϵ��ַ������ַ���2����ĸ���ֻ�ϵ��ַ���������ĸ�Ӵ��������Ӵ�����ͬ��˳����ȽϽ��Ϊͬ���Ӵ��ıȽϽ��
TEST(StringCompare, GIVEN_String1_MixAlphaWithDigit_String2_MixAlphaWithDigit_And_SubString_InSamePosition_WHEN_Compare_THEN_ResultIsStrCmpOrNumericValueCompare)
{
	// ��ĸ�Ӵ�-�����Ӵ�
	EXPECT_EQ(StringCompare("abc123", "abd90"), -1);
	EXPECT_EQ(StringCompare("abc123", "abc90"), 1);

	EXPECT_EQ(StringCompare("abc123", "abc123"), 0);

	// �ַ���1����ĸ�Ӵ�-�����Ӵ��� �ַ���2����ĸ�Ӵ�
	EXPECT_EQ(StringCompare("abc123", "abc"), 1);

	// �ַ���1����ĸ�Ӵ����ַ���2����ĸ�Ӵ�-�����Ӵ�
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


// --------------������ת��Ϊ�ַ���������ʼ

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


// --------------����ĸת��Ϊ���ֵ�������ʼ

// �ַ���1��������ĸ��ת����ĸ�����֣��ַ���2��������ĸ��ת����ĸ������
TEST(StringCompare, GIVEN_String1_AlphabetEscapeAlphabetDigit_String2_AlphabetEscapeAlphabetDigit_WHEN_Compare_THEN_ResultSameWithStrcmp)
{
	EXPECT_EQ(StringCompare("123\\a5", "12345"), 1);
	EXPECT_EQ(StringCompare("97", "\\a"), 1);
	EXPECT_EQ(StringCompare("65", "\\A"), 1);
	EXPECT_EQ(StringCompare("97", "0\\a"), 0);
	EXPECT_EQ(StringCompare("65", "0\\A"), 0);
	EXPECT_EQ(StringCompare("122", "00\\z"), 0);
	EXPECT_EQ(StringCompare("122", "\\z"), 1);

	EXPECT_EQ(StringCompare("065", "0\\A"), 1);

	EXPECT_EQ(StringCompare("1\\A\\A", "815"), 0);
	EXPECT_EQ(StringCompare("01\\A\\A", "815"), 1);
	EXPECT_EQ(StringCompare("1\\A\\A", "0815"), -1);
}

// �ַ���1�������Ƿ��ַ����ַ���2��������ĸ��ת����ĸ�����֣����������-2
TEST(StringCompare, GIVEN_String1_InvalidChar_String2_AlphabetEscapeAlphabetDigit_WHEN_Compare_THEN_ReturnInvalidValue)
{
	EXPECT_EQ(StringCompare("123.5", "12345"), -2);
	EXPECT_EQ(StringCompare("12345\\", "12345"), -2);
	EXPECT_EQ(StringCompare("12345\\.", "12345"), -2);

	EXPECT_EQ(StringCompare("abcd\\", "abcd"), -2);
	EXPECT_EQ(StringCompare("abcd\\.", "abcd"), -2);
	EXPECT_EQ(StringCompare("ab.cd\\.", "abcd"), -2);
}

// �մ�
TEST(StringCompare, GIVEN_String1_Or_String2_IsEmpty_WHEN_Compare_THEN_EmptyLittleThanNonEmpty)
{
	EXPECT_EQ(StringCompare("", "12345"), -1);
	EXPECT_EQ(StringCompare("", "abcd"), -1);

	EXPECT_EQ(StringCompare("abc123", ""), 1);

	EXPECT_EQ(StringCompare("", ""), 0);
}

