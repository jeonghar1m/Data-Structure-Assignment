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
    //�����͵� �����ؾ��ϹǷ�"="�ٿ�����!
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
            //� ��쵵 �ƴ� �� ex) 3 4 5 7�϶� 6����
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
    //������� �˻�, 1:������� 0:�����������
    if (is_empty(head))
        printf("is_empty = TRUE\n");
    else if(!is_empty(head))
        printf("is_empty = FALSE\n");
    //���ʿ� ���������� 7���� �����������λ��Խ�Ŵ
    printf("7���� ���Ҹ� �����մϴ�.\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &item);
        add(head, &item);
    }
    printf("����Ʈ�� ���̸� ����մϴ�.%d\n", get_length(head));
    printf("����Ʈ�� ��� ��Ҹ� ����մϴ�.\n");
    display(head);
    //Ư�� ���� ����Ʈ�� �ִ��� Ž���غ���.
    printf("����Ʈ�� �����ϴ��� ������ ����: ");
    scanf("%d", &item);
    temp = is_in_list(head, item);
    if (temp == NULL)
        printf("����\n");
    else
        printf("%d��(��)�ֽ��ϴ�.\n", temp->data);

    //����Ʈ���ִ� ������ �Ѱ� ����
    printf("����Ʈ�� ���� �� �����ϰ� ���� ����: ");
    scanf("%d", &item);
    temp = is_in_list(head, item);
    if (temp == NULL)printf("����\n");
    else
    {
        delete(head, temp->data, len);
        printf("���ŵǾ����ϴ�.\n");
    }
    //�����ϰ� ���� ��� Ȯ��
    printf("����Ʈ�� ��� ��Ҹ� ����մϴ�.\n");
    display(head);
    printf("�����ִ� ������ ������ %d���Դϴ�.\n", get_length(head));
    //��� �����ϱ� 
    printf("����Ʈ�� ���Ҹ� ��� �����ϰڽ��ϴ�.\n");
    clear(head, len);
    printf("����Ʈ�� �����ִ� ���Ҹ� ����մϴ�.\n");
    display(head);

    printf("����Ʈ�� ������� �˻�: %d\n", is_empty(head));
}