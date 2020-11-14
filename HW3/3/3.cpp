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

	//더미 헤드와 더미 테일 노드의 초기화
	header.data = NULL;		// 초기화하지만 사용하지는 않는 데이터
	header.llink = NULL;
	header.rlink = &trailer;

	trailer.data = NULL;	// 초기화하지만 사용하지는 않는 데이터
	trailer.llink = &header;
	trailer.rlink = NULL;

	//리스트의 초기화
	head = &header;

	int menu_select = 0;
	int app_select = 0;
	int value = 0;
	char* app = nullptr;

	while (menu_select != 4)
	{
		printf("메뉴를 선택해주세요. 1. 앱 실행, 2. 앱 종료, 3. 실행 중 앱 출력, 4. 프로그램 종료\n");
		scanf("%d", &menu_select);

		switch (menu_select)
		{
		case ADD:
		{
			//printf("구동할 앱을 선택하세요.\n");
			//printf("1. 카카오톡, 2. 페이스북, 3. 인스타그램\t입력: ");
			//scanf("%d", &app_select);
			//if (app_select == 1)
			//	add(head, "카카오톡");
			//else if (app_select == 2)
			//	add(head, "페이스북");
			//else if (app_select == 3)
			//	add(head, "인스타그램");
			printf("몇 개의 앱을 구동하시겠습니까?\t입력: ");
			scanf("%d", value);
			if (value > 0)
			{
				printf("실행시킬 앱의 이름을 입력해주세요.\n");
				for (int i = 0; i < value; i++)
				{
					scanf("%s", &app);
					add(head, app);
				}
			}
			else
				printf("잘못된 입력입니다.\n");
			break;
		}
		case REMOVE:
		{
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