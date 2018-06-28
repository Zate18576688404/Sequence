#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<cstring>
class Sequence
{
private:
	string DNA;
public:
	Sequence(string filename);
	int length();
	int numberOf(char base);
	string longestConsecutive();
	string longestRepeated();
        int comlen(char *p, char *q);
        int pstrcmp(const void *p1, const void *p2);
};
#endif

