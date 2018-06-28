nclude<iostream>
#include<string>
#include<cstring>
#include<fstream>
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
	return sizeof(DNA);
}
int Sequence::numberOf(char base)
{
	long long number = 0;
	for (int i = 0; i<sizeof(DNA); i++)
	{
		if (DNA[i] == base)
			number++;
	}
	return number;
}
string Sequence::longestConsecutive()
{
	int k1 = 0; char DNAm;
	for (int i = 0; i<sizeof(DNA); i++)
	{
		int k2 = 0;

		for (int j = i + 1; j<sizeof(DNA); j++)
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
	for (int i = 0; i<k1; i++)
		LongDNA+=DNAm;
	return LongDNA;

}
char A[2000000], *B[20000000];
string Sequence::longestRepeated()
{
	for (int i = 0; i < sizeof(DNA); i++)
	{
		A[i] = DNA[i];
		B[i] = &A[i];
    }
	B[sizeof(DNA)] = 0;
	B[sizeof(DNA) + 1] = 0;

	qsort(B, sizeof(DNA), sizeof(char*), ZAT);

	string Repeated;
	int max1 = -1, t, pos = 0;
	for (int i = 0; i < sizeof(DNA); i++)
	{
		t = R(B[i - 1], B[1]);
			if (t>max1)
			{
				max1 = t;
				pos = i;
			}

	}

				for (int i = 0; i < max1; i++)
			{
				Repeated += B[pos][i];
			}
			return Repeated;
	
	}
int Sequence::R(char*a, char*b)
	{
		int i = 0;
		while (*a&&(*a++==*b++))
		{
			i++;
		}
		return i;
     }
int ZAT(const void *a, const void *b)
{
	char **pa = (char**)a;
	char **pb = (char**)b;
	return strcmp(*pa, *pb);

}
