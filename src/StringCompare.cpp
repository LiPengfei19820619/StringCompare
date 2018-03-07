#include "StringCompare.h"

#include "StringSplitter.h"
#include "DigitSubString.h"
#include "CharSubString.h"

int StringCompare(const std::string &str1, const std::string &str2)
{
	ComparableSubString *sub1 = StringSplitter::Split(str1);
	ComparableSubString *sub2 = StringSplitter::Split(str2);

	return sub1->Compare(*sub2);

	/*CharSubString substr1;
	CharSubString substr2;

	substr1.Scan(str1);
	substr2.Scan(str2);

	return substr1.Compare(substr2);*/

	//DigitSubString substr1;
	//DigitSubString substr2;

	//substr1.Scan(str1);
	//substr2.Scan(str2);

	//return substr1.Compare(substr2);
}
