#include <iostream>
using namespace std;
double calculate(int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)	//이거 안해주면 프로그램 종료가 너무 느림.(최적화)
		return 0;
	else
		return (double)1 / n + calculate(n - 1);
}
int main()
{
	int i = 0;
	do
	{
		cout << "값을 입력해주세요. 0을 입력시 종료됩니다. ";
		cin >> i;
		cout << calculate(i) << endl;
	} while (i != 0);

	return 0;
}