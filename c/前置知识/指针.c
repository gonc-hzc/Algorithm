#include <stdio.h>

int main()
{
    int a;
    int * p;
    a = 5;
    p = &a;
    printf("%d\n",*p);

    printf("p的地址为：%p , p的值为：%p\n" , &p , p);
    printf("a的地址为：%p , a的值为：%d\n" , &a , a);

    *p = 10;
    printf("%d\n",a);
    return 0;
}