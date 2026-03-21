//设计一个函数，传入两个int参数，并交换这两个参数的值
#include <stdio.h>

void swap(int * num1 , int * num2)
{
    int temp;
    temp = * num2;
    * num2 = * num1;
    *num1 = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    swap(&a,&b);
    printf("a的值为：%d\n",a);
    printf("b的值为：%d\n",b);
    return 0;
}