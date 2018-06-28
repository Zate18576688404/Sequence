#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<cstring>
class Sequence
{
private:
	string DNA;
	int R(char*a, char*b);
public:
	Sequence(string filename);
	int length();
	int numberOf(char base);
	string longestConsecutive();
	string longestRepeated();
};
#endif

