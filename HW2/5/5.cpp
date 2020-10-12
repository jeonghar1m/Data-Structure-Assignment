#include <iostream>
using namespace std;
int sum(int n)
{
	//기존 순환적 구조의 소스코드
	/*if (n == 1)
		return 1;
	else
		return (n + sum(n - 1));*/
	int temp = 0;
	if (n == 1)
		temp = n;
	else
	{
		for (n; n >= 1; n--)
			temp += n;
	}
	
	return temp;
}
int main()
{
	cout << sum(10) << endl;
}