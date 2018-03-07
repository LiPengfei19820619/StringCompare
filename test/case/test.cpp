#include "StringCompare.h"

#include "gtest/gtest.h"


TEST(StringCompare, 1)
{
	EXPECT_EQ(StringCompare("11", "22"), 0);
}