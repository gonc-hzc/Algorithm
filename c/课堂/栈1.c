/*
编写一个算法，要求将非负的十进制整数转换成其他进制的数输出，10及其以上的数字从'A'开始的字母表示

核心内容：
1. 顺序栈的定义和操作
2. 栈先进后出的特性解决问题

要求：
采用顺序栈，在键盘中输入一个十进制数，输出相应八进制和十六进制数

思路：
整数：进制转换是通过不断做取余操作，求得的余数从低位排到高位构成新进制对应的数
其中栈先进后出的特点刚好满足从低位到高位排数的需求
*/

// #include <stdio.h>
// #include <stdlib.h>

// #define MAXSIZE 100

// //定义栈结构体
// typedef struct 
// {
//     int  data[MAXSIZE]; //存栈中元素
//     int top;            //栈顶指针（top初始化为-1,入栈先top++再存数据，出栈先取出数据在top--）
// }SeqStack;

// //初始化栈
// void Stack_Init(SeqStack * stc)
// {
//     stc->top = -1;
// }

// //判断栈是否为空
// int IsEmpty(SeqStack * stc)
// {
//     return stc->top == -1;
// }

// //判断栈是否已满
// int IsFull(SeqStack * stc)
// {
//     return stc->top == MAXSIZE -1;
// }

// //入栈
// int Push(SeqStack * stc , int x)
// {
//     if(IsFull(stc))
//     {
//         return 0; //入栈失败
//     }
//     stc->data[++(stc->top)] = x;
//     return 1; //入栈成功
// }

// //出栈
// int Pop(SeqStack * stc , int * x)
// {
//     if(IsEmpty(stc))
//     {
//         return 0; //出栈失败
//     }
//     *x = stc->data[stc->top--];
//     return 1; //出栈成功
// }

// //转换算法
// void Convert(int origin_num , int base)  //origin_num是原数，base是目标进制
// {
//     SeqStack stc;
//     int x;
    
//     Stack_Init(&stc);

//     if(origin_num ==0)
//     {
//         printf("0");
//         return;
//     }

//     while(origin_num > 0)
//     {
//         Push(&stc , origin_num % base);
//         origin_num = origin_num / base;
//     }

//     while(!IsEmpty(&stc))  //while在做合并输出（每个单独的余数在视觉上拼接成对应进制完整的数）
//     {
//         Pop(&stc , &x);
//         if(x < 10)
//         {
//             printf("%d" , x);
//         }
//         else
//         {
//             printf("%c" , 'A'+(x - 10));
//         }
//     }
// }

// int main()
// {
//     int n1;
//     printf("请输入一个十进制非负整数： ");
//     scanf("%d",&n1);

//     printf("对应八进制数为： ");
//     Convert(n1 , 8);
//     printf("\n");

//     printf("对应十进制数为： ");
//     Convert(n1 , 16);
//     printf("\n");

//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100  //定义栈最大空间

//定义栈结构
typedef struct
{
    int data[MAXSIZE];  //栈存储的元素
    int top;  //栈顶指针
}Stack;

//初始化栈
void InitStack(Stack * stk)
{
    stk->top = -1;  //栈顶指针初始化为-1 
}

//判空
int isEmpty(Stack * stk)
{
    return stk->top == -1;
}

//判满
int isFull(Stack * stk)
{
    return stk->top == MAXSIZE-1;
}

//入栈
int Push(Stack * stk , int x)
{
    if(isFull(stk))
    {
        return 0;  //入栈失败
    }
    stk->data[++stk->top] = x;
    return 1;
}

//出栈
int Pop(Stack * stk , int * x)
{
    if(isEmpty(stk))
    {
        return 0;  //出栈失败
    }
    *x = stk->data[stk->top--];
    return 1;
}

//转换算法
void Convert(int origin_nums, int base)
{
    Stack stk;
    int temp;
    int value;

    InitStack(&stk);

    if(origin_nums == 0)
    {
        printf("0");
        return;
    }

    while(origin_nums > 0)
    {
        temp = origin_nums % base;
        origin_nums /= base;

        Push(&stk , temp);
    }

    while(!isEmpty(&stk))
    {
        Pop(&stk , &value);
        if(value < 10)
        {
            printf("%d" , value);
        }
        else
        {
            printf("%c" , 'A'+(value-10));  //这里做的是ascll码运算
        }
    }
}

int main()
{
    int num1;

    printf("请输入十进制非负整数： ");
    scanf("%d" , &num1);

    printf("转换成八进制： ");
    Convert(num1 , 8);
    printf("\n");

    printf("转换成十六进制： ");
    Convert(num1 , 16);
    printf("\n");

    return 0;
}





