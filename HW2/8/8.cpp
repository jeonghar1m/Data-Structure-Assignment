#include <iostream>
using namespace std;
void main()
{
	char str[100] = {};			//���ڸ� ��� �迭
	int length = 0;				//���ڿ��� ����
	bool isPalindrome = true;	//ȸ�� ����

	cout << "���ڿ��� �Է��Ͻÿ�: ";
	cin >> str;

	length = strlen(str);		//str ���ڿ��� ���� ����

	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	if (isPalindrome)
		cout << "ȸ���Դϴ�." << endl;
	else
		cout << "ȸ���� �ƴմϴ�." << endl;
}