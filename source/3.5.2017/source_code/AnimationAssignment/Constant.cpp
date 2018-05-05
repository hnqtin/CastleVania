#include<fstream>
#include<string>
#include<map>
using namespace std;
void ignoreLineIfstream(ifstream& fs, int lineCount)
{
	string s;
	for (int i = 0; i < lineCount; i++)
	{
		std::getline(fs, s);
	}
}

map<const char*, double> params;

void initParams()
{
	params["actionIndex"] = 1;
}