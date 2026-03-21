#include <stdio.h>

int main()
{
    int a[] = {15,22,67,43,87};
    int * p;
    p = a;  //等价于 p = &a[0];

    printf("a的地址为：%p\n",a);
    printf("p的地址为：%p\n",p);
    printf("p值向的值为：%d\n",*p);

    for(int i = 0; i < sizeof(a)/sizeof(a[0])  ; i++)
    {
        printf("%d\n",*p);
        p++;
    }

    p=a;

    for(int i = 0; i < sizeof(a)/sizeof(a[0]) ; i++)
    {
        printf("%d\n",*(p+i));
    }

    return 0;
}