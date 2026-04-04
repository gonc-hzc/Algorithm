#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int score;
    struct Node *next;
} Node;

// 按学生人数建立链表
Node* CreateScoreList(int n)
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    Node *tail = head;
    int x;

    printf("请输入 %d 个学生的成绩：\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        Node *p = (Node*)malloc(sizeof(Node));
        p->score = x;
        p->next = NULL;

        tail->next = p;
        tail = p;
    }

    return head;
}

// 输出成绩链表
void PrintScoreList(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->score);
        p = p->next;
    }
    printf("\n");
}

// 统计不及格人数
int CountFail(Node *head)
{
    int count = 0;
    Node *p = head->next;

    while (p != NULL)
    {
        if (p->score < 60)
        {
            count++;
        }
        p = p->next;
    }

    return count;
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
    int n;
    printf("请输入学生人数：");
    scanf("%d", &n);

    Node *head = CreateScoreList(n);

    printf("学生成绩为：");
    PrintScoreList(head);

    int failCount = CountFail(head);
    printf("不及格人数为：%d\n", failCount);

    FreeList(head);
    return 0;
}