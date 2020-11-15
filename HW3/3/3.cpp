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

enum menu
{
	ADD = 1, REMOVE, PRINT, QUIT
};

unsigned int countList(DNode* head)
{
	int len = 0;
	DNode* temp = head;
	for (temp; temp != NULL; temp = temp->rlink)
		len++;
	return len;
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
	DNode* p = nullptr;
	p->llink = head;
	p->rlink = head->rlink;
	head->rlink->llink = p;
	head->rlink = p;

	return p;
}

DNode* search(DNode* head, const char* str)
{
	DNode* temp = head;
	for (temp; temp != NULL; temp = temp->rlink)
		if (temp->data == str)
			return temp;
	return temp;
}

DNode* remove(DNode* head, DNode* p)
{
	if (p == head)
		return p;
	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	free(p);
}

int main()
{
	DNode header;
	DNode trailer;
	DNode* head = NULL;
	DNode* temp = NULL;

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
	int app_select = 0;
	int value = 0;
	char* app = nullptr;

	while (menu_select != 4)
	{
		printf("�޴��� �������ּ���. 1. �� ����, 2. �� ����, 3. ���� �� �� ���, 4. ���α׷� ����\n");
		scanf("%d", &menu_select);

		switch (menu_select)
		{
		case ADD:
		{
			printf("�� ���� ���� �����Ͻðڽ��ϱ�?\t�Է�: ");
			scanf("%d", value);
			if (value > 0)
			{
				printf("�����ų ���� �̸��� �Է����ּ���.\n");
				for (int i = 0; i < value; i++)
				{
					scanf("%s", &app);
					add(head, app);
				}
			}
			else
				printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
		case REMOVE:
		{
			printf("������ ���� �̸��� �Է����ּ���.\t�Է�: ");
			scanf("%d", &app);
			temp = search(head, app);
			if (temp == NULL)
				printf("���� ã�� �� �����ϴ�.");
			else
			{
				
			}

			break;
		}
		case PRINT:
		{
			break;
		}
		case QUIT:
			return 0;
		}
	}
	return 0;
}