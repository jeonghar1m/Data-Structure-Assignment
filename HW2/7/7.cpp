#include <iostream>
using namespace std;
void main()
{
	char str[10] = {};			//���ڸ� ��� �迭
	int no[10] = {};			//��ȣ�� �����Ǵ� ���ڸ� ��� �迭
	int amount = 0;				//���� ��ȣ�� ����
	int cnt = 0;				//loop�� ����
	bool isFirstClose = true;	//ù ��° �ݴ� ��ȣ

	cout << "����: ";
	while (1)
	{
		char ch;
		ch = cin.get();
		if(ch=='\n')
			break;
		str[cnt] = ch;
		cnt++;
	}
	for (int i = 0; i < cnt; i++)	//��ĵ
	{
		if (str[i] == '(')
		{
			amount++;
			no[i] = amount;
			isFirstClose = true;	//���� ��ȣ�� �ްԵǸ� �� �ٽ� ������ ��ȣ�� ���� ��쿡 ���ڸ� ��Ī������� �ϱ� ����.
		}
		else if (str[i] == ')' && isFirstClose)
		{
			no[i] = amount;
			isFirstClose = false;
		}
		else if (str[i] == ')' && !isFirstClose)
		{
			amount--;
			no[i] = amount;
		}
		else
		{
			cout << "�߸��� �Է��� �޾����Ƿ� ���α׷��� ������ �����մϴ�." << endl;
			return;
		}
	}

	cout << "��ȣ ��: ";
	for (int i = 0; i < cnt; i++)
		cout << no[i] << ' ';
	cout << endl;
}