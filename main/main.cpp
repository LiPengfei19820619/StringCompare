#include "StringCompare.h"

#include <string>

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("Usage: StringCompare str1 str2\n");
		return -2;
	}

	std::string str1 = argv[1];
	std::string str2 = argv[2];

	int result = StringCompare(str1, str2);

	printf("result is:%d\n", result);
	return result;
}
