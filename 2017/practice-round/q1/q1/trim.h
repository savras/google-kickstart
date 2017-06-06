#pragma once
#include "string"

using std::string;

class trim
{
public:
	static void ltrim(std::string &s);
	static void rtrim(std::string &s);
	static void trimBoth(std::string &s);
	static std::string ltrimmed(std::string);
	static std::string rtrimmed(std::string);
	static std::string trimmed(std::string);
};