#include <iostream>
using namespace std;
double calculate(int n)
{
	if (n == 1)
		return 1;
	else if (n == 0)	//�̰� �����ָ� ���α׷� ���ᰡ �ʹ� ����.(����ȭ)
		return 0;
	else
		return (double)1 / n + calculate(n - 1);
}
int main()
{
	int i = 0;
	do
	{
		cout << "���� �Է����ּ���. 0�� �Է½� ����˴ϴ�. ";
		cin >> i;
		cout << calculate(i) << endl;
	} while (i != 0);

	return 0;
}