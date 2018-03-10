#include "StringCompare.h"

#include "gtest/gtest.h"


// 两个纯字符的字符串比较
TEST(StringCompare, GIVEN_Two_Strings_With_Only_Chars_WHEN_Compare_THEN_Strcmp)
{
	EXPECT_EQ(StringCompare("abc", "abd"), -1);
}

// 两个纯数字的字符串比较
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

// 两个字符数字混合的字符串(字符子串和数字子串对应)比较
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

// 纯字符的串和纯数字的串进行比较(规则(3)如果被比较的一边是子数字串，一边是子字母串，则子数字串小；)
TEST(StringCompare, GIVEN_String1_PureChars_String2_PureDigits_WHEN_Compare_THEN_String1_BiggerThan_String2)
{
	EXPECT_EQ(StringCompare("abc", "90"), 1);
	EXPECT_EQ(StringCompare("abcdefghijklmnopqrstuvwxyz", "01234567890123456789012345678901234567890123456789"), 1);
}

// 纯数字的串和纯字母的串进行比较(规则(3)如果被比较的一边是子数字串，一边是子字母串，则子数字串小；)
TEST(StringCompare, GIVEN_String1_PureDigits_String2_PureAlphabets_WHEN_Compare_THEN_String1_LittleThan_String2)
{
	EXPECT_EQ(StringCompare("90", "abc"), -1);
	EXPECT_EQ(StringCompare("01234567890123456789012345678901234567890123456789", "abcdefghijklmnopqrstuvwxyz"), -1);
}

// 两个字符数字混合的字符串(字符子串和数字子串不对应)比较
TEST(StringCompare, GIVEN_Two_Strings_With_Digits_And_Chars_NotInSamePosition_WHEN_Compare_THEN_GetResult)
{
	EXPECT_EQ(StringCompare("90abc", "abc90"), -1);
}

// 字符串1：包含数字转义为字符，字符串2：包含纯字母
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

// 字符串1：包含字母、转义数字、数字，字符串2：包含字母、转义数字、数字
TEST(StringCompare, GIVEN_String1_AlphabetEscapeDigit_String2_AlphabetDigit_WHEN_Compare_THEN_ResultSameWithStrcmp)
{
	EXPECT_EQ(StringCompare("abc\\123456789", "abc\\23456789"), -1);
	EXPECT_EQ(StringCompare("abc\\12\\3def", "abc\\123def"), 0);
}

// 字符串1：包含字母、转义字母、数字，字符串2：包含字母、转义字母、数字
TEST(StringCompare, GIVEN_String1_AlphabetEscapeAlphabetDigit_String2_AlphabetEscapeAlphabetDigit_WHEN_Compare_THEN_ResultSameWithStrcmp)
{
	EXPECT_EQ(StringCompare("123\\a5", "12345"), 1);
	EXPECT_EQ(StringCompare("97", "\\a"), 1);
	EXPECT_EQ(StringCompare("65", "\\A"), 1);
	EXPECT_EQ(StringCompare("97", "0\\a"), 0);
	EXPECT_EQ(StringCompare("65", "0\\A"), 0);

	EXPECT_EQ(StringCompare("065", "0\\A"), 1);
}

// 字符串1：包含非法字符，字符串2：包含字母、转义字母、数字，结果：返回-2
TEST(StringCompare, GIVEN_String1_InvalidChar_String2_AlphabetEscapeAlphabetDigit_WHEN_Compare_THEN_ReturnMinus2)
{
	EXPECT_EQ(StringCompare("123.5", "12345"), -2);
	EXPECT_EQ(StringCompare("12345\\", "12345"), -2);
}

