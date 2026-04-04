// 顺序表
/*
已知有两个顺序表 A 和 B，里面的元素都已经是从小到大排好序的，设计一个算法将A B的全部元素合并成按照元素值递增有序的顺序表 C
要求：键盘输入A B各元素，输出A B C
*/

/*
思路1：双指针
i：指向 A 当前元素
j：指向 B 当前元素
k：指向 C 当前要放的位置

A[i] < B[j] 放入A[i]  反之放入B[j]，哪个表的元素被放入,相应下标后移
*/

#include <stdio.h>

#define MAXSIZE 100

//顺序表结构体
typedef struct
{
    int data[MAXSIZE];
    int length;
} SeqList;

//输入函数
void InputList(SeqList * List , char name)
{
    printf("请输入顺序表 %c 的元素个数：" , name);
    scanf("%d" , &List->length);

    printf("请按递增顺序输入顺序表 %c 的元素：" , name);
    for(int i = 0 ; i < List->length ; i++)
    {
        scanf("%d" , &List->data[i]);
    }
}

//输出顺序表
void PrintList(SeqList List , char name)
{
    printf("顺序表 %c：" , name);
    for(int i = 0 ; i < List.length ; i++)
    {
        printf("%d" , List.data[i]);
        printf("\n");
}
    }
    

//合并顺序表
void MergeList(SeqList A , SeqList B , SeqList *C)
{
    int i = 0 , j = 0 , k = 0 ;
    while(i < A.length && j < B.length)
    {
        if(A.data[i] <= B.data[j])
        {
            C->data[k++] = A.data[i++];
        }
        else
        {
            C->data[k++] = B.data[j++];
        }
    }

    //A有剩余
    while(i < A.length)
    {
        C->data[k++] = A.data[i++];
    }

    //B有剩余
    while(j < B.length)
    {
        C->data[k++] = B.data[j++];
    }

    C->length = k;
}

int main()
{
    SeqList A , B , C;

    InputList(&A , 'A');
    InputList(&B , 'B');
    
    MergeList(A , B , &C );

    PrintList(A , 'A');
    PrintList(B , 'B');
    PrintList(C , 'C');

    return 0;

}