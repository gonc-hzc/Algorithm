# include <stdio.h>

#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int length;
} SeqList;

//输入顺序表
void InputList(SeqList * L)
{
    int i;
    printf("请输入顺序表的元素个数：");
    scanf("%d",&L->length);

    printf("请输入顺序表的元素：");
    for(int i = 0 ; i < L->length ; i++)
    {
        scanf("%d" , &L->data[i]);
    }
}

//输出顺序表
void OutputList(SeqList L)
{
    int i;
    for(i = 0 ; i < L.length - 1 ; i++)
    {
        printf("%d",L.data[i]);
    }
    printf("\n");
}

//交换两个整数
void Swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//将奇数移到偶数前
void Move(SeqList * L)
{
    int left = 0;
    int right = L->length-1;

    while(left < right)
    {
        //从左找偶数
        while(left < right && L->data[left] % 2 != 0)
        {
            left++;
        }

        //从右找偶数
        while(left < right && L->data[right] % 2 ==0)
        {
            right--;
        }

        //交换
        if(left < right)
        {
            Swap(&L->data[left] , &L->data[right]);
        }
    }
}

int main()
{
    SeqList A;

    InputList(&A);

    printf("调整前: ");
    OutputList(A);

    Move(&A);

    printf("调整后: ");
    OutputList(A);

    return 0;
}