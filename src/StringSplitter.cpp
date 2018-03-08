#include "StringSplitter.h"

#include "CharSubString.h"
#include "DigitSubString.h"

bool StringSplitter::Split(const std::string &str, std::vector<ComparableSubString *> &substrs)
{
	size_t cur_index = 0;

	for (cur_index = 0; cur_index < str.length(); cur_index++)
	{
		if (isalpha(str[0]))
		{
			CharSubString *sub = new CharSubString();
			sub->Scan(str, cur_index, cur_index);
			substrs.push_back(sub);
		}
		if (isdigit(str[0]))
		{
			DigitSubString *sub = new DigitSubString();
			sub->Scan(str,cur_index, cur_index);
			substrs.push_back(sub);
		}
	}
	return true;
}