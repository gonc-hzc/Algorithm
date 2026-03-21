#include <stdio.h>

int main()
{
    int a[] = {46,87,49,38,16};

    for(int i = 0 ; i < sizeof(a)/sizeof(a[0]) ; i++)
    {
        printf("%d\n",a[i]);
    }

    printf("%zu\n",sizeof(a));

    //取数组的地址
    printf("%p\n",&a);
    printf("%p\n",&a[0]);
    return 0;
}