#ifndef STRUTILS_H
#define STRUTILS_H

#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include<boost/tokenizer.hpp>

using namespace std;
using namespace boost;

void Tokenize(const string& str, vector<int>& tokens, boost::char_separator<char>& delimiter);
void Tokenize(const string& str, vector<string>& tokens, boost::char_separator<char>& delimiter);
string  Str(const int val);
string crop(string str, char what);
int StrtoInt(const std::string& s);

#endif
