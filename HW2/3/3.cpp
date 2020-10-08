#include <iostream>
using namespace std;
void unknown()
{
	int ch;
	if ((ch = getchar()) != '\n')
		unknown();
	putchar(ch);
}
int main()
{
	unknown();
	string s;
	cin >> s;

	return 0;
}