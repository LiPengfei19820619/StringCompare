#include "StringCompare.h"

#include "StringSplitter.h"
#include "DigitSubString.h"
#include "CharSubString.h"

int StringCompare(const std::string &str1, const std::string &str2)
{
	std::vector<ComparableSubString *> substrs1;
	std::vector<ComparableSubString *> substrs2;

	StringSplitter::Split(str1, substrs1);
	StringSplitter::Split(str2, substrs2);

	std::vector<ComparableSubString *>::iterator it1;
	std::vector<ComparableSubString *>::iterator it2;

	for (it1 = substrs1.begin(), it2 = substrs2.begin();
		 it1 != substrs1.end()&&it2 != substrs2.end();
		 it1++, it2++)
	{
		int result = (*it1)->Compare(*(*it2));
		if (result != 0)
		{
			return result;
		}
	}

	if (it1 == substrs1.end() && it2 == substrs2.end())
	{
		return 0;
	}
	if (it1 == substrs1.end())
	{
		return -1;
	}

	return 1;

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
