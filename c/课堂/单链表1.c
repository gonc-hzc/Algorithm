#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 尾插法建立单链表
Node* CreateList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    Node *tail = head;
    int x;

    printf("请输入 8 个整数：\n");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &x);

        Node *p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;

        tail->next = p;
        tail = p;
    }

    return head;
}

// 输出链表
void PrintList(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 查找最大值结点
Node* FindMaxNode(Node *head)
{
    Node *p = head->next;
    if (p == NULL)
    {
        return NULL;
    }

    Node *maxNode = p;
    p = p->next;

    while (p != NULL)
    {
        if (p->data > maxNode->data)
        {
            maxNode = p;
        }
        p = p->next;
    }

    return maxNode;
}

// 释放链表
void FreeList(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

int main()
{
    Node *head = CreateList();

    printf("单链表中的元素为：");
    PrintList(head);

    Node *maxNode = FindMaxNode(head);
    if (maxNode != NULL)
    {
        printf("最大值结点的数据为：%d\n", maxNode->data);
    }

    FreeList(head);
    return 0;
}