#pragma once

#include "ComparableSubString.h"
#include <string>

class CharSubString : public ComparableSubString
{
public:
	void Scan(const std::string &str, size_t begin_index, size_t &end_index);

	int Compare(const ComparableSubString &substr);
	bool IsCharString() const;
	bool IsDigitString() const;

private:
	bool Append(const std::string &str, size_t cur_index, size_t &next_index);

	bool AppendNonEscapeChar(const std::string &str, size_t cur_index, size_t &next_index);
	bool AppendEscapeChar(const std::string &str, size_t cur_index, size_t &next_index);

	bool BeginAppendEscapeChar(const std::string &str, size_t cur_index, size_t &next_index);
	bool ContinueAppendEscapeChar(const std::string &str, size_t cur_index, size_t &next_index);

	void StartEscape();
	void EndEscape();

	bool HasReachMaxEscapeLen() const;

	std::string _value;

	bool _is_escape;
	int _has_escaped_len;

	static const int MAX_ESCAPE_LEN = 3;
};