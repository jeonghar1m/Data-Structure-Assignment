#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 200000

typedef int element;

typedef struct Stack
{
	element data[MAX_STACK_SIZE] = {};
	int top;
} stack;

void initialize(stack *s)
{
	s->top = -1;
}

int is_empty(stack* s)
{
	if (s->top == -1)
		return TRUE;
	else
		return FALSE;
}

int is_full(stack* s)
{
	if (s->top == (MAX_STACK_SIZE - 1))
		return TRUE;
	else
		return FALSE;
}

void push(stack* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "Stack is full!\n");
		return;
	}
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

element pop(stack* s)
{
	element temp;

	if (is_empty(s))
	{
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}
	else
	{
		temp = s->data[s->top];
		(s->top)--;
		return temp;
	}
}

int main()
{
	clock_t start, finish;
	double duration;
	int i;

	Stack s;

	initialize(&s);

	start = clock();

	for (i = 0; i < MAX_STACK_SIZE; i++)
	{
		push(&s, 1);
		pop(&s);
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf초입니다.\n", duration);

	return 0;
}