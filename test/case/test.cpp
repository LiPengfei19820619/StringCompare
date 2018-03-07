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
}