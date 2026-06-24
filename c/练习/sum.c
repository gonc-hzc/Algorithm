#include <stdio.h>

/*
需求：计算 1 加到 100 的值并输出
*/

void func()
{
    int sum = 0; //用来接收累积值/

    for(int i = 0 ; i <= 100 ; i++)
    {
        //累加
        sum += i;
    }

    printf("sum= %d\n",sum);
}

int func_re()
{
    int sum = 0;

    for(int i = 0; i <= 100 ; i++)
    {
        sum += i;
    }

    return sum;
}

/*
需求2:从 1 加到 n ，n在调用函数的时候作为函数传入
*/

void func_n(int n)
{
    int s_n = 0;
    for(int i = 0 ; i <= n ; i++)
    {
        s_n += i;
    }

    printf("s_n = %d\n" , s_n);
}

int main()
{
    func();

    int res = func_re();
    printf("s = %d\n" , res);

    func_n(100);

    return 0;
}