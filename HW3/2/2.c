#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
	int data;
	struct node* link;
} Node;

Node* create_node(int item)
{
	Node* p = NULL;

	p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(1);
	}
	p->data = item;
	p->link = NULL;

	return p;
}

Node* add(Node* head, int item)
{
	Node* p = create_node(item);

	p->link = head;
	head = p;

	return head;
}

Node* delete(Node* head, int item)
{
	Node* removed;
	removed = item;
	item = removed->link;
	free(removed);
	return head;
}

void clear(Node* head)
{
	while (!is_empty())
		popBack();
}

int is_in_list(Node* head, int item)
{

}

unsigned int get_length(Node* head)
{

}

int is_empty(Node* head)
{

}

void print_list(Node* head)
{

}

int main()
{
	return 0;
}