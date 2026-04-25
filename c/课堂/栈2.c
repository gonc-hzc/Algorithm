#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链栈结点
typedef struct StackNode
{
    char data;
    struct StackNode *next;
} StackNode;

// 链栈
typedef struct
{
    StackNode *top;
} LinkStack;

// 初始化
void InitStack(LinkStack *s)
{
    s->top = NULL;
}

// 入栈
void Push(LinkStack *s, char x)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = s->top;
    s->top = node;
}

// 出栈
int Pop(LinkStack *s, char *x)
{
    if (s->top == NULL)
        return 0;

    StackNode *temp = s->top;
    *x = temp->data;
    s->top = temp->next;
    free(temp);
    return 1;
}

// 判断回文
int isPalindrome(char str[])
{
    LinkStack s;
    InitStack(&s);

    int len = strlen(str);

    // 入栈
    for (int i = 0; i < len; i++)
    {
        Push(&s, str[i]);
    }

    // 出栈比较
    for (int i = 0; i < len; i++)
    {
        char ch;
        Pop(&s, &ch);

        if (ch != str[i])
            return 0; // 不是回文
    }

    return 1; // 是回文
}

// 主函数
int main()
{
    char str[100];

    printf("请输入字符串: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("是回文串\n");
    else
        printf("不是回文串\n");

    return 0;
}