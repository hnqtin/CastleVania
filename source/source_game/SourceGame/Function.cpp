#include<fstream>
#include<string>
using namespace std;
void ignoreLineIfstream(ifstream& fs, int lineCount)
{
	string s;
	for (int i = 0; i < lineCount; i++)
	{
		std::getline(fs, s);
	}
}

int getRandom(int start, int end)
{
	return rand() % (end - start + 1) + start;
}
