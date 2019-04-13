#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
	string line;
	ifstream infile(filename);

	vector<string> sents;

	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			sents.push_back(line);
		}
	}
	map<string, int> strings;
	for (auto& i:sents)
	{
		strings[i]++;
	}
	map<int,string> temp;
	for(auto& i:strings){
		temp[i.second]=i.first;
	}
	string ret="";
	for(auto& i:temp){
		ret=ret+i.second;
		ret=ret+" ";

	}
	ret.pop_back();
	infile.close();
	return ret;
}
