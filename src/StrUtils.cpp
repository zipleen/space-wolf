#include "StrUtils.h"
#ifdef _DEBUG
#include <iostream>
#endif
string crop(string str, char what)
{
	string aux = "";
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if(str[i] != what)
			aux += str[i];
	}
	return aux;
}

int split(vector<string>& v, const string& str, char c)
{
	v.clear();
	string::const_iterator s = str.begin();
	while (true) {
		string::const_iterator begin = s;
	
		while (*s != c && s != str.end()) { ++s; }
	
		v.push_back(string(begin, s));
	
		if (s == str.end()) {
		break;
		}
		if (++s == str.end()) {
			// v.push_back("");
			break;
		}
	}
	return v.size();
}
 
int split2(vector<string>& v, const string& str, char c, char d)
{
	v.clear();
	string::const_iterator s = str.begin();
	while (true) {
		string::const_iterator begin = s;
		
		while ( (*s != c && *s!=d) && s != str.end()) { ++s; }
		
		v.push_back(string(begin, s));
		
		if (s == str.end()) {
			break;
		}
		if (++s == str.end()) {
			// v.push_back("");
			break;
		}
	}
	return v.size();
}

int splitInt(vector<int>& v, const string& str, char c)
{
	v.clear();
	string::const_iterator s = str.begin();
	while (true) {
		string::const_iterator begin = s;
		
		while (*s != c && s != str.end()) { ++s; }
		
		stringstream ss(string(begin, s));
		int n;
		ss >> n;
		
		v.push_back(n);
		
		if (s == str.end()) {
			break;
		}
		if (++s == str.end()) {
			// v.push_back("");
			break;
		}
	}
	return v.size();
}


void Tokenize(const string& str, vector<string>& tokens, const string& delimiters)
{
	split(tokens, str, delimiters[0]);
}

void Tokenize(const string& str, vector<string>& tokens, const char& delimiter)
{
	split(tokens, str, delimiter);
}

void Tokenize(const string& str, vector<string>& tokens, const char& delimiter, const char& delimiter2)
{
	split2(tokens, str, delimiter, delimiter2);
}

string Str(const int val)
{
	char buf[32];
	sprintf(buf, "%d", val);
	return buf;
}

void Tokenize(const string& str, vector<int>& tokens, const char& delimiter)
{
	splitInt(tokens, str, delimiter);
}
