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

enum menu
{
    ISEMPTY = 1, INPUT, OUTPUT, SEARCH, REMOVE, CLEAR
};

Node add(Node **head, int item)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = item;
    p->link = NULL;
    Node* pos = *head;
    if (*head == NULL) {
        *head = p;
    }

    else if (p->data <= (*head)->data)
    {
        p->link = *head;
        *head = p;
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

            pos = pos->link;
        }
    }
}
void delete(Node **head, int item, int len)
{
    Node* removed;
    if ((*head)->link == NULL)
    {
        free(head);
        *head = NULL;
    }
    else if ((*head)->data == item)
    {
        removed = head;
        head = (*head)->link;
        free(removed);
    }
    else {
        Node* pre = *head;
        for (pre; pre->link->data != item; pre = pre->link);
            removed = pre->link;
        pre->link = removed->link;
        free(removed);
    }
    len--;
}
void clear(Node **head, int len)
{
    Node* removed;
    Node* temp = *head;
    while (1)
    {
        removed = temp;
        if (removed == NULL)
            break;
        *head = (*head)->link;
        temp = temp->link;
        free(removed);

    }
}
int *is_in_list(Node *head, int item)
{
    Node *temp = head;
    for (temp; temp != NULL; temp = temp->link)
        if (temp->data == item)
            return temp;

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
    int select = 0;
    Node* head = NULL;
    Node* temp = NULL;

    do
    {
        printf("�޴��� �������ּ���. 1. is_empty Ȯ��, 2. �Է�, 3. ���, 4. Ž��, 5. ����, 6. ��� ����\n");
        scanf("%d", &select);
        switch (select)
        {
        case ISEMPTY:
            {
                if (is_empty(head))
                    printf("is_empty = TRUE\n");
                else if (!is_empty(head))
                    printf("is_empty = FALSE\n");
                break;
            }
        case INPUT:
            {
                printf("5���� ���Ҹ� �����մϴ�.\n");
                for (int i = 0; i < 5; i++) {
                    scanf("%d", &item);
                    add(&head, item);
                }
                break;
            }
        case OUTPUT:
            {
                printf("����Ʈ�� ���̸� ����մϴ�.%d\n", get_length(head));
                printf("����Ʈ�� ��� ��Ҹ� ����մϴ�.\n");
                display(head);
                break;
            }
        case SEARCH:
            {

                printf("����Ʈ�� �����ϴ��� ������ ����: ");
                scanf("%d", &item);
                temp = is_in_list(head, item);
                if (temp != NULL)
                    printf("%d��(��)�ֽ��ϴ�.\n", temp->data);
                else
                    printf("����\n");
                break;
            }
        case REMOVE:
            {

                printf("����Ʈ�� ���� �� �����ϰ� ���� ����: ");
                scanf("%d", &item);
                temp = is_in_list(head, item);
                if (temp == NULL)
                    printf("����\n");
                else
                {
                    delete(&head, temp->data, len);
                    printf("���ŵǾ����ϴ�.\n");
                }

                printf("����Ʈ�� ��� ��Ҹ� ����մϴ�.\n");
                display(head);
                printf("�����ִ� ������ ������ %d���Դϴ�.\n", get_length(head));
                break;
            }
        case CLEAR:
            {
                    printf("����Ʈ�� ���Ҹ� ��� �����ϰڽ��ϴ�.\n");
                    clear(&head, len);
                    printf("����Ʈ�� �����ִ� ���Ҹ� ����մϴ�.\n");
                    display(head);
                    break;
            }
        }
    } while (select != 0);
}