#include "StrUtils.h"

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



string Str(const int val)
{
	char buf[32];
	sprintf(buf, "%d", val);
	return buf;
}



void StringSplit(string str, string delim, vector<string>& results)
{
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos )
	{
		if(cutAt > 0)
		{
			results.push_back(str.substr(0,cutAt));
		}
		str = str.substr(cutAt+1);
	}
	if(str.length() > 0)
	{
		results.push_back(str);
	}
}

void Tokenize(const string& str, vector<string>& tokens, boost::char_separator<char>& delimiter)
{
	boost::tokenizer<boost::char_separator<char> > tok(str,delimiter);
	tokens.clear();
	for(boost::tokenizer<boost::char_separator<char> >::iterator beg=tok.begin(); beg!=tok.end();++beg){
		tokens.push_back(*beg);
	}
}	

void Tokenize(const string& str, vector<int>& tokens, boost::char_separator<char>& delimiter)
{
	boost::tokenizer<boost::char_separator<char> > tok(str,delimiter);
	tokens.clear();
	for(boost::tokenizer<boost::char_separator<char> >::iterator beg=tok.begin(); beg!=tok.end();++beg){
		stringstream ss(*beg);
		int n;
		ss >> n;
		tokens.push_back(n);
	}
	
    /*std::vector< std::string > SplitVec;
	StringSplit( str,  delimiter, SplitVec);
	tokens.clear();
	for(int i = 0; i<SplitVec.size(); ++i){
		stringstream ss(SplitVec[i]);
		int n;
		ss >> n;
		tokens.push_back(n);
	}*/
	
    /*std::vector< std::string > SplitVec;
	boost::split( SplitVec, str, delimiter ); 
	
	*/
	
}

int StrtoInt(const std::string& s)
{
	stringstream ss(s);
	int n;
	ss >> n;
	return n;
}
