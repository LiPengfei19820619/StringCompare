#include "StringSplitter.h"

#include "CharSubString.h"
#include "DigitSubString.h"

bool StringSplitter::Split(const std::string &str, std::vector<ComparableSubString *> &substrs)
{
	size_t cur_index = 0;

	while (cur_index < str.length())
	{
		if (isalpha(str[cur_index]))
		{
			CharSubString *sub = new CharSubString();
			sub->Scan(str, cur_index, cur_index);
			substrs.push_back(sub);
		}
		else if (isdigit(str[cur_index]))
		{
			DigitSubString *sub = new DigitSubString();
			sub->Scan(str,cur_index, cur_index);
			substrs.push_back(sub);
		}
		else
		{

		}
	}
	return true;
}