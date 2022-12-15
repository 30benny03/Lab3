#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

int main()
{
	ifstream f("html.txt");
	string s;
	smatch m;
	
	const auto r = regex(R"(<a.+?href=\"(.+?)\"(.+?>|>).+?<\/a>)");
	while (getline(f, s))
	{
		regex_search(s, m, r);
		if(!m.empty()) cout << m[0] << "\n\n";
	}
}