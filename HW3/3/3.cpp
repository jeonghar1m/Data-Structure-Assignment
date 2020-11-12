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

unsigned int countList(DNode* head)
{

}

void print_list(DNode* head)
{

}

DNode* createNode(const char* str)
{

}

DNode* add(DNode *head, int item)
{

}

DNode* search(DNode* head, const char* str)
{

}

DNode* remove(DNode* head, DNode* p)
{

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

	while (menu_select != 4)
	{
		printf("메뉴를 선택해주세요. 1. 앱 실행, 2. 앱 종료, 3. 실행 중 앱 출력, 4. 프로그램 종료\n");
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