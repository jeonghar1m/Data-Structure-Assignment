#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 50
typedef char element;
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty()
{
	return (top == -1);
}

//포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(element item)
{
	if (is_full())
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		stack[++top] = item;
}

//삭제 함수
element pop()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return stack[top--];
}

//피크 함수
element peek()
{
	if (is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return stack[top];
}

int main()
{
	char temp_buf[MAX_STACK_SIZE] = "";
	char result_buf[MAX_STACK_SIZE] = "";	//pop
	int cnt = 0;	//문자열의 크기를 담을 int 변수
	printf("문자열을 입력하세요: ");
	scanf("%s", &temp_buf);

	for (int i = 0; i < MAX_STACK_SIZE; i++)
	{
		if (temp_buf[i] == '\0')
			break;
		push(temp_buf[i]);
	}
	printf("Input: %s\n", stack);
	cnt = strlen(stack);

	for (int i = 0; i < cnt; i++)
	{
		result_buf[i] = pop();
	}

	printf("Output: %s\n", result_buf);

	return 0;
}