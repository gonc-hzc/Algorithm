#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// 定义环形队列
typedef struct
{
    int data[MAXSIZE];
    int front;   // 队头指针
    int rear;    // 队尾指针
} CircleQueue;

// 初始化队列
void InitQueue(CircleQueue *q)
{
    q->front = 0;
    q->rear = 0;
}

// 判空
int IsEmpty(CircleQueue *q)
{
    return q->front == q->rear;
}

// 判满
int IsFull(CircleQueue *q)
{
    return (q->rear + 1) % MAXSIZE == q->front;
}

// 入队
int EnQueue(CircleQueue *q, int x)
{
    if (IsFull(q))
    {
        return 0;   // 队满，入队失败
    }

    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

// 出队
int DeQueue(CircleQueue *q, int *x)
{
    if (IsEmpty(q))
    {
        return 0;   // 队空，出队失败
    }

    *x = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

// 输出队列中所有元素
void PrintQueue(CircleQueue *q)
{
    int i;

    if (IsEmpty(q))
    {
        printf("队列为空！\n");
        return;
    }

    printf("队列中的元素为：");
    i = q->front;
    while (i != q->rear)
    {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main()
{
    CircleQueue q;
    int a, x;

    InitQueue(&q);

    printf("请输入整数序列（输入0结束）：\n");

    while (1)
    {
        scanf("%d", &a);

        if (a == 0)
        {
            break;   // 输入结束
        }
        else if (a < 0)
        {
            if (EnQueue(&q, a))
            {
                printf("%d 已进队。\n", a);
            }
            else
            {
                printf("队列已满，%d 无法进队！\n", a);
            }
        }
        else   // a > 0
        {
            if (DeQueue(&q, &x))
            {
                printf("队首元素 %d 已出队。\n", x);
            }
            else
            {
                printf("队列为空，无法出队！\n");
            }
        }
    }

    PrintQueue(&q);

    return 0;
}