#include<iostream>
#include<vector>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<algorithm>
#include"Sequence.h"
using namespace std;
Sequence::Sequence(string filename)
{
	fstream file;
	file.open(filename, ios::in);
	if (!file)
		cout << "file not founded" << endl;
	string DNA0;
	while (!file.eof())
	{
		getline(file, DNA0,'\n');
		DNA += DNA0;
	}
}
int Sequence::length()
{
	return DNA.length();
}
int Sequence::numberOf(char base)
{
	long long number = 0;
	for (int i = 0; i<DNA.length(); i++)
	{
		if (DNA[i] == base)
			number++;
	}
	return number;
}
string Sequence::longestConsecutive()
{
	int k1 = 0; char DNAm;
	for (int i = 0; i<DNA.length(); i++)
	{
		int k2 = 0;

		for (int j = i + 1; j<DNA.length(); j++)
		{
			if (DNA[j] == DNA[i])
				k2++;
			else
				break;
		}
		if (k2>k1)
		{
			k1 = k2;
			DNAm = DNA[i];
		}
	}
	string LongDNA;
	for (int i = 0; i<=k1; i++)
		LongDNA+=DNAm;
	return LongDNA;

}
string Sequence::longestRepeated()
{
        int maxcommonlength = 0;
	string repeat;
	vector<string> dna(DNA.length());

	for (int i = 0; i < DNA.size(); i++)
		dna[i] = DNA.substr(DNA.length() - i - 1, i + 1);
	sort(dna.begin(), dna.end());

	for (int i = 0; i < dna.size() - 1; i++)
	{
		string c = dna[i];
		string s = dna[i + 1];

		int t = 0;
		for (int j = 0; j < min(c.length(), s.length()); j++)
		{
			if (c[j] != s[j])
			{
				t = 0;
				break;
			}
			else
				t++;
			if (maxcommonlength < t)
			{
				maxcommonlength = t;
				repeat = s.substr(0, maxcommonlength);
			}
		}
	}
return repeat;
}
int Sequence::comlen(char *p, char *q)
{
	int i = 0;
	while (*p && (*p++ == *q++))
		++i;
	return i;
}
int Sequence::pstrcmp(const void *p1, const void *p2)
{
	return strcmp(*(char* const *)p1, *(char *const*)p2);
}
