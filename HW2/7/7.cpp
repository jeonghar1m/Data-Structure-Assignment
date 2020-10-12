#include <iostream>
using namespace std;
void main()
{
	char str[10] = {};			//문자를 담는 배열
	int no[10] = {};			//괄호에 대응되는 숫자를 담는 배열
	int amount = 0;				//여는 괄호의 갯수
	int cnt = 0;				//loop용 변수
	bool isFirstClose = true;	//첫 번째 닫는 괄호

	cout << "수식: ";
	while (1)
	{
		char ch;
		ch = cin.get();
		if(ch=='\n')
			break;
		str[cnt] = ch;
		cnt++;
	}
	for (int i = 0; i < cnt; i++)	//스캔
	{
		if (str[i] == '(')
		{
			amount++;
			no[i] = amount;
			isFirstClose = true;	//여는 괄호를 받게되면 또 다시 닫히는 괄호가 나올 경우에 숫자를 매칭시켜줘야 하기 때문.
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
			cout << "잘못된 입력을 받았으므로 프로그램을 강제로 종료합니다." << endl;
			return;
		}
	}

	cout << "괄호 수: ";
	for (int i = 0; i < cnt; i++)
		cout << no[i] << ' ';
	cout << endl;
}