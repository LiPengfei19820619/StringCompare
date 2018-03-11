#pragma once

#include <string>

#define STRING_COMPARE_RESULT_LITTLE                -1
#define STRING_COMPARE_RESULT_GREATER               1
#define STRING_COMPARE_RESULT_EQUAL                 0
#define STRING_COMPARE_RESULT_INVALID_STRING        -2

int StringCompare(const std::string &str1, const std::string &str2);
