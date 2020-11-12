#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
    int data;
    struct node* link;
}Node;

Node *add(Node *head, int item)
{
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node));
    p->data = item;
    p->link = NULL;
    Node* pos = head;
    if (head == NULL) {
        head = p;
    }
    //같은것도 삽입해야하므로"="붙여야함!
    else if (p->data <= head->data)
    {
        p->link = head;
        head = p;
    }
    else
    {
        while (1)
        {
            if (pos->link == NULL)
            {
                pos->link = p;
                break;
            }
            else if (p->data < pos->link->data)
            {
                p->link = pos->link;
                pos->link = p;
                break;
            }
            //어떤 경우도 아닐 때 ex) 3 4 5 7일때 6삽입
            pos = pos->link;
        }
    }

    return p;
}
void *delete(Node *head, int item, int len)
{
    Node* removed;
    if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else if (head->data == item)
    {
        removed = head;
        head = head->link;
        free(removed);
    }
    else {
        Node* pre = head;
        for (pre; pre->link->data != item; pre = pre->link);
        removed = pre->link;
        pre->link = removed->link;
        free(removed);
    }

    return head;
}
void clear(Node *head, int len)
{
    Node* removed;
    Node* temp = head;
    while (1)
    {
        removed = temp;
        if (removed == NULL)
            break;
        head = head->link;
        temp = temp->link;
        free(removed);

    }
}
Node* is_in_list(Node *head, int item)
{
    Node* temp = head;
    for (temp; temp != NULL; temp = temp->link)
        if (temp->data == item) temp = TRUE;
            //return temp;
        else temp = FALSE;

    return temp;
}
unsigned int get_length(Node *head)
{
    int len = 0;
    Node* temp = head;
    for (temp; temp != NULL; temp = temp->link)
        len++;
    return len;
}
int is_empty(Node* list)
{
    //return list == NULL;
    if (list == NULL)
        return TRUE;
    else
        return FALSE;
}
void display(Node* list)
{
    Node* temp = list;
    for (temp; temp != NULL; temp = temp->link)
        printf("%d ", temp->data);
    printf("\n");
}
int main()
{
    int item;
    int len = 0;
    Node* head = NULL;
    Node* temp = NULL;
    //비었는지 검사, 1:비어있음 0:비어있지않음
    if (is_empty(head))
        printf("is_empty = TRUE\n");
    else if(!is_empty(head))
        printf("is_empty = FALSE\n");
    //최초에 무작위숫자 7개를 오름차순으로삽입시킴
    printf("7개의 원소를 삽입합니다.\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &item);
        add(head, &item);
    }
    printf("리스트의 길이를 출력합니다.%d\n", get_length(head));
    printf("리스트의 모든 요소를 출력합니다.\n");
    display(head);
    //특정 값이 리스트에 있는지 탐색해본다.
    printf("리스트에 존재하는지 조사할 숫자: ");
    scanf("%d", &item);
    temp = is_in_list(head, item);
    if (temp == NULL)
        printf("없음\n");
    else
        printf("%d이(가)있습니다.\n", temp->data);

    //리스트에있는 원소중 한개 제거
    printf("리스트의 원소 중 제거하고 싶은 숫자: ");
    scanf("%d", &item);
    temp = is_in_list(head, item);
    if (temp == NULL)printf("없음\n");
    else
    {
        delete(head, temp->data, len);
        printf("제거되었습니다.\n");
    }
    //삭제하고 나서 요소 확인
    printf("리스트의 모든 요소를 출력합니다.\n");
    display(head);
    printf("남아있는 원소의 갯수는 %d개입니다.\n", get_length(head));
    //모두 제거하기 
    printf("리스트의 원소를 모두 제거하겠습니다.\n");
    clear(head, len);
    printf("리스트에 남아있는 원소를 출력합니다.\n");
    display(head);

    printf("리스트가 비었는지 검사: %d\n", is_empty(head));
}