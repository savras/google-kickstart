// https://stackoverflow.com/questions/9321/how-do-you-create-a-static-class-in-c
// https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

#include "trim.h"
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

// trim from start (in place)
void trim::ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),	std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
void trim::rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
void trim::trimBoth(std::string &s) {
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
std::string trim::ltrimmed(std::string s) {
	ltrim(s);
	return s;
}

// trim from end (copying)
std::string trim::rtrimmed(std::string s) {
	rtrim(s);
	return s;
}

// trim from both ends (copying)
std::string trim::trimmed(std::string s) {
	trimBoth(s);
	return s;
}