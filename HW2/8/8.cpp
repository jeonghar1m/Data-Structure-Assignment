#include <iostream>
using namespace std;
void main()
{
	char str[100] = {};			//문자를 담는 배열
	int length = 0;				//문자열의 길이
	bool isPalindrome = true;	//회문 여부

	cout << "문자열을 입력하시오: ";
	cin >> str;

	length = strlen(str);		//str 문자열의 길이 대입

	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	if (isPalindrome)
		cout << "회문입니다." << endl;
	else
		cout << "회문이 아닙니다." << endl;
}