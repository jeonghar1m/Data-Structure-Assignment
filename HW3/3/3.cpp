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
	header.data = NULL;
	header.llink = NULL;
	header.rlink = &trailer;

	trailer.data = NULL;
	trailer.llink = &header;
	trailer.rlink = NULL;

	//리스트의 초기화
	head = &header;
}