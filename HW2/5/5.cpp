#include <iostream>
using namespace std;
int sum(int n)
{
	//���� ��ȯ�� ������ �ҽ��ڵ�
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
	cout << sum(5) << endl;
}