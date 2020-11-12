#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Dnode
{
	char* data;
	struct Dnode* llink;
	struct Dnode* rlink;
}DNode;

void init(DNode* head)
{
	head->llink = head;
	head->rlink = head;
}

unsigned int countList(DNode* head)
{

}

void print_list(DNode* head)
{
	DNode* p;
	p = head;
	for(p=head->rlink; p != head; p = p->rlink)
	{
		printf("%s -->", p->data);
		p = p->rlink;
	}
	printf("%s", p -> data);
}

DNode* createNode(char* str)
{
	DNode* newnode = (DNode*)malloc(sizeof(DNode));
	newnode->llink = NULL;
	newnode->data = str;
	newnode->rlink = NULL;
	return newnode;
}

DNode* add(DNode *head, char* item)
{
	DNode* newnode = createNode(item);
	DNode* p;
	p->llink = head;
	p->rlink = head->rlink;
	head->rlink->llink = p;
	head->rlink = p;
}

DNode* search(DNode* head, const char* str)
{

}

DNode* remove(DNode* head, DNode* p)
{
	if (p == head)
		return;
	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	free(p);
}

int main()
{
	DNode header;
	DNode trailer;
	DNode* head = NULL;

	//���� ���� ���� ���� ����� �ʱ�ȭ
	header.data = NULL;		// �ʱ�ȭ������ ��������� �ʴ� ������
	header.llink = NULL;
	header.rlink = &trailer;

	trailer.data = NULL;	// �ʱ�ȭ������ ��������� �ʴ� ������
	trailer.llink = &header;
	trailer.rlink = NULL;

	//����Ʈ�� �ʱ�ȭ
	head = &header;

	int menu_select = 0;

	while (menu_select != 4)
	{
		printf("�޴��� �������ּ���. 1. �� ����, 2. �� ����, 3. ���� �� �� ���, 4. ���α׷� ����\n");
		scanf("%d", &menu_select);

		switch (menu_select)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
			return 0;
		}
	}
	return 0;
}