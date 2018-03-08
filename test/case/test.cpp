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

	EXPECT_EQ(StringCompare("000000001234", "00000001234"), 1);
	EXPECT_EQ(StringCompare("00000001234", "000000001234"), -1);

	EXPECT_EQ(StringCompare("123456789012345678901234567890", "123456789012345678901234567890"), 0);
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "00000123456789012345678901234567890"), 0);
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "0000123456789012345678901234567890"), 1);
	EXPECT_EQ(StringCompare("0000123456789012345678901234567890", "00000123456789012345678901234567890"), -1);

	EXPECT_EQ(StringCompare("123456789012345678901234567895", "123456789012345678901234567890"), 1);
	EXPECT_EQ(StringCompare("123456789012345678901234567895", "123456789012345678901234567898"), -1);
}

// 两个字符数字混合的字符串比较
TEST(StringCompare, GIVEN_Two_Strings_With_Digits_And_Chars_WHEN_Compare_THEN_GetResult)
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