#include "StringCompare.h"

#include "gtest/gtest.h"


// ---------- 两个纯字母的字符串比较用例开始

// 字符串1：纯字母的字符串，字符串2：包含纯字母的字符串，根据strcmp规则字符串1小于字符串2，则比较结果为-1
TEST(StringCompare, GIVEN_String1_WithOnlyAlphabetChars_String2_WithOnlyAlphabetChars_String1LittleThanString2_WHEN_StringCompare_THEN_Get_Little)
{
	EXPECT_EQ(StringCompare("abc", "abd"), -1);
	EXPECT_EQ(StringCompare("abc", "abcd"), -1);
	EXPECT_EQ(StringCompare("abc", "bcd"), -1);
	EXPECT_EQ(StringCompare("baby", "father"), -1);
	EXPECT_EQ(StringCompare("BABY", "FATHER"), -1);
}

// 字符串1：纯字母的字符串，字符串2：包含纯字母的字符串，根据strcmp规则字符串1等于于字符串2，则比较结果为0
TEST(StringCompare, GIVEN_String1_WithOnlyAlphabetChars_String2_WithOnlyAlphabetChars_String1EqualToString2_WHEN_StringCompare_THEN_Get_Equal)
{
	EXPECT_EQ(StringCompare("abcdefg", "abcdefg"), 0);
}

// 字符串1：纯字母的字符串，字符串2：包含纯字母的字符串，根据strcmp规则字符串1大于字符串2，则比较结果为1
TEST(StringCompare, GIVEN_String1_WithOnlyAlphabetChars_String2_WithOnlyAlphabetChars_String1GreaterThanString2_WHEN_StringCompare_THEN_Get_Greater)
{
	EXPECT_EQ(StringCompare("bcdefg", "abcdefgh"), 1);
	EXPECT_EQ(StringCompare("bcdefghxyz", "bcdefgh"), 1);
	EXPECT_EQ(StringCompare("bcdxyz", "bcdefgh"), 1);
}


// ----------两个纯数字的字符串比较用例开始

// 字符串1：纯数字，字符串2：纯数字，字符串1的数字值小于字符串2的数字值，则比较结果为-1
TEST(StringCompare, GIVEN_String1_WithOnlyDigits_String2_WithOnlyDigits_String1NumericValueLitter_WHEN_Compare_THEN_Get_Little)
{
	EXPECT_EQ(StringCompare("92", "256"), -1);
	EXPECT_EQ(StringCompare("902", "2560"), -1);
	EXPECT_EQ(StringCompare("902", "920"), -1);
	EXPECT_EQ(StringCompare("092", "256"), -1);
	EXPECT_EQ(StringCompare("92", "0256"), -1);
	EXPECT_EQ(StringCompare("00092", "00256"), -1);
}

// 字符串1：纯数字，字符串2：纯数字，字符串1的数字值大于字符串2的数字值，则比较结果为1
TEST(StringCompare, GIVEN_String1_WithOnlyDigits_String2_WithOnlyDigits_String1NumericValueGreater_WHEN_Compare_THEN_Get_Greater)
{
	EXPECT_EQ(StringCompare("492", "256"), 1);
	EXPECT_EQ(StringCompare("0492", "256"), 1);
	EXPECT_EQ(StringCompare("492", "0256"), 1);
	EXPECT_EQ(StringCompare("0492", "0256"), 1);
	EXPECT_EQ(StringCompare("0492", "000256"), 1);
}

// 字符串1：纯数字，字符串2：纯数字，字符串1的数字值等于字符串2的数字值，则比较结果为子串长的较大
TEST(StringCompare, GIVEN_String1_WithOnlyDigits_String2_WithOnlyDigits_String1NumericValueEqual_WHEN_Compare_THEN_LongerIsGreater)
{
	EXPECT_EQ(StringCompare("492", "492"), 0);
	EXPECT_EQ(StringCompare("0492", "492"), 1);
	EXPECT_EQ(StringCompare("492", "0492"), -1);
	EXPECT_EQ(StringCompare("0492", "0492"), 0);
	EXPECT_EQ(StringCompare("0492", "000492"), -1);
}

// 字符串1：超长的纯数字，字符串2：超长的纯数字，字符串1的数字值小于字符串2的数字值，则比较结果为-1
TEST(StringCompare, GIVEN_String1_WithOnlyDigitsVeryLong_String2_WithOnlyDigitsVeryLong_String1NumericValueLitter_WHEN_Compare_THEN_Get_Little)
{
	EXPECT_EQ(StringCompare("123456789012345678901234567895", "123456789012345678901234567898"), -1);
}

// 字符串1：超长的纯数字，字符串2：超长的纯数字，字符串1的数字值大于字符串2的数字值，则比较结果为1
TEST(StringCompare, GIVEN_String1_WithOnlyDigitsVeryLong_String2_WithOnlyDigitsVeryLong_String1NumericValueGreater_WHEN_Compare_THEN_Get_Greater)
{
	EXPECT_EQ(StringCompare("123456789012345678901234567895", "123456789012345678901234567890"), 1);
}

// 字符串1：超长的纯数字，字符串2：超长的纯数字，字符串1的数字值等于字符串2的数字值，则比较结果为子串长的较大
TEST(StringCompare, GIVEN_String1_WithOnlyDigitsVeryLong_String2_WithOnlyDigitsVeryLong_String1NumericValueEqual_WHEN_Compare_THEN_LongerIsGreater)
{
	EXPECT_EQ(StringCompare("123456789012345678901234567890", "123456789012345678901234567890"), 0);

	// 前面都是5个0
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "00000123456789012345678901234567890"), 0);

	// 字符串1前面5个0，字符串2前面4个0
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "0000123456789012345678901234567890"), 1);

	// 字符串1前面5个0，字符串2前面6个0
	EXPECT_EQ(StringCompare("00000123456789012345678901234567890", "000000123456789012345678901234567890"), -1);
}


// -----------------两个字符数字混合的字符串比较

// 字符串1：字母数字混合的字符串，字符串2：字母数字混合的字符串，且字母子串和数字子串在相同的顺序，则比较结果为同类子串的比较结果
TEST(StringCompare, GIVEN_String1_MixAlphaWithDigit_String2_MixAlphaWithDigit_And_SubString_InSamePosition_WHEN_Compare_THEN_ResultIsStrCmpOrNumericValueCompare)
{
	// 字母子串-数字子串
	EXPECT_EQ(StringCompare("abc123", "abd90"), -1);
	EXPECT_EQ(StringCompare("abc123", "abc90"), 1);

	EXPECT_EQ(StringCompare("abc123", "abc123"), 0);

	// 字符串1：字母子串-数字子串， 字符串2：字母子串
	EXPECT_EQ(StringCompare("abc123", "abc"), 1);

	// 字符串1：字母子串，字符串2：字母子串-数字子串
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


// --------------由数字转义为字符的用例开始

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


// --------------由数母转义为数字的用例开始

// 字符串1：包含字母、转义字母、数字，字符串2：包含字母、转义字母、数字
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

// 字符串1：包含非法字符，字符串2：包含字母、转义字母、数字，结果：返回-2
TEST(StringCompare, GIVEN_String1_InvalidChar_String2_AlphabetEscapeAlphabetDigit_WHEN_Compare_THEN_ReturnInvalidValue)
{
	EXPECT_EQ(StringCompare("123.5", "12345"), -2);
	EXPECT_EQ(StringCompare("12345\\", "12345"), -2);
	EXPECT_EQ(StringCompare("12345\\.", "12345"), -2);

	EXPECT_EQ(StringCompare("abcd\\", "abcd"), -2);
	EXPECT_EQ(StringCompare("abcd\\.", "abcd"), -2);
	EXPECT_EQ(StringCompare("ab.cd\\.", "abcd"), -2);
}

// 空串
TEST(StringCompare, GIVEN_String1_Or_String2_IsEmpty_WHEN_Compare_THEN_EmptyLittleThanNonEmpty)
{
	EXPECT_EQ(StringCompare("", "12345"), -1);
	EXPECT_EQ(StringCompare("", "abcd"), -1);

	EXPECT_EQ(StringCompare("abc123", ""), 1);

	EXPECT_EQ(StringCompare("", ""), 0);
}

