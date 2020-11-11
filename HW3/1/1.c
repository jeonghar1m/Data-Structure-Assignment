#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 50
typedef char element;
element stack[MAX_STACK_SIZE];
int top = -1;

//���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(element item)
{
	if (is_full())
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		stack[++top] = item;
}

//���� �Լ�
element pop()
{
	if (is_empty())
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return stack[top--];
}

//��ũ �Լ�
element peek()
{
	if (is_empty())
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return stack[top];
}

int main()
{
	char temp_buf[MAX_STACK_SIZE] = "";
	char result_buf[MAX_STACK_SIZE] = "";	//pop
	int cnt = 0;	//���ڿ��� ũ�⸦ ���� int ����
	printf("���ڿ��� �Է��ϼ���: ");
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