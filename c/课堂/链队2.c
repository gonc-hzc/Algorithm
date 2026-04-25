#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 50

// 定义病人结点
typedef struct QNode
{
    char name[NAMELEN];
    struct QNode *next;
} QNode;

// 定义链队列
typedef struct
{
    QNode *front;   // 队头指针
    QNode *rear;    // 队尾指针
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// 判空
int IsEmpty(LinkQueue *q)
{
    return q->front == NULL;
}

// 入队：病人到达
void EnQueue(LinkQueue *q, char name[])
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    strcpy(p->name, name);
    p->next = NULL;

    if (IsEmpty(q))
    {
        q->front = p;
        q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}

// 出队：医生叫号
int DeQueue(LinkQueue *q, char name[])
{
    QNode *p;

    if (IsEmpty(q))
    {
        return 0;   // 队空
    }

    p = q->front;
    strcpy(name, p->name);

    q->front = p->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(p);
    return 1;
}

// 输出当前排队情况
void PrintQueue(LinkQueue *q)
{
    QNode *p;

    if (IsEmpty(q))
    {
        printf("当前没有病人排队。\n");
        return;
    }

    printf("当前排队的病人有：\n");
    p = q->front;
    while (p != NULL)
    {
        printf("%s\n", p->name);
        p = p->next;
    }
}

// 主函数
int main()
{
    LinkQueue q;
    int choice;
    char name[NAMELEN];

    InitQueue(&q);

    while (1)
    {
        printf("\n===== 医院排队叫号系统 =====\n");
        printf("1. 病人到达（入队）\n");
        printf("2. 医生叫号（出队）\n");
        printf("3. 查看排队情况\n");
        printf("4. 退出系统\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("请输入病人姓名：");
                scanf("%s", name);
                EnQueue(&q, name);
                printf("病人 %s 已进入候诊队列。\n", name);
                break;

            case 2:
                if (DeQueue(&q, name))
                {
                    printf("请病人 %s 进入诊室就诊。\n", name);
                }
                else
                {
                    printf("当前没有病人排队！\n");
                }
                break;

            case 3:
                PrintQueue(&q);
                break;

            case 4:
                printf("系统已退出。\n");
                return 0;

            default:
                printf("输入有误，请重新选择！\n");
        }
    }

    return 0;
}