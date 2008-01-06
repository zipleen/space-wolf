#ifndef STRUTILS_H
#define STRUTILS_H

#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include<boost/tokenizer.hpp>

using namespace std;
using namespace boost;

void Tokenize(const string& str, vector<string>& tokens, const char& delimiter = (char)1);
void Tokenize(const string& str, vector<int>& tokens, boost::char_separator<char>& delimiter);
string  Str(const int val);
string crop(string str, char what);

#endif
