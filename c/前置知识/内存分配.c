/*
使用malloc函数分配内存
void* malloc(size_t)
分配成功：返回堆区内存的指针
分配失败：返回空指针

free()函数释放分配在堆区的内存
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;
}po;

int main()
{
    //分配1个元素的堆内存
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 15;
    printf("p = %d\n" , *p);
    free(p);
    p = NULL;

    //分配一个数组的堆内存
    int *arr = (int*)malloc(5*sizeof(int));
    int len = 5 ;
    printf("len = %d\n" , len);
    for(int i = 0 ; i < len ; i++)
    {
        arr[i] = 0;
    }

    for(int i = 0 ; i < len ; i++)
    {
        printf("%d\n" , arr[i]);
    }

    free(arr);
    arr = NULL;

    //分配内存给结构体
    po * st;
    st = (po*)malloc(sizeof(po));
    st -> x = 5;
    st -> y = 10;
    printf("%d\n" , st->x);
    printf("%d\n" , st->y);

    free(st);
    st = NULL;

    return 0;
}
