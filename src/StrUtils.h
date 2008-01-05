#ifndef STRUTILS_H
#define STRUTILS_H

#include <vector>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ");
void Tokenize(const string& str, vector<string>& tokens, const char& delimiter = (char)1);
void Tokenize(const string& str, vector<string>& tokens, const char& delimiter, const char& delimiter2);
void Tokenize(const string& str, vector<int>& tokens, const char& delimiter);
string  Str(const int val);
string crop(string str, char what);

#endif
