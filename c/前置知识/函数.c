#include <stdio.h>

//函数实现 1 加到 100
int func()
{
    int sum = 0;
    for(int i = 1 ; i < 101 ; i++)
    {
        sum += i;
    }
    return sum;
}

int main(int argc , char const *argv[])
{
    int sum = 0;
    for(int i = 1; i <= 100 ; i++)
    {
        sum += i;
    }
    printf("sum=%d\n",sum);


    printf("sum = %d\n ", func());

    return 0;
}