/*
顺序表是以数组的形式存储数据元素的线性表。它具有以下特点：
1. 顺序表中的数据元素在内存中是连续存储的，因此可以通过下标直接访问任意位置的元素，访问速度快。
2. 顺序表的长度是固定的，在创建顺序表时需要指定其最大容量。如果需要存储更多的数据元素，则需要重新分配内存空间，这可能会导致性能下降。
3. 顺序表的插入和删除操作可能需要移动大量元素，因此在频繁进行插入和删除操作的情况下，顺序表的性能可能不如链表。
4. 顺序表适合于需要快速访问元素的场景，例如查找和遍历操作
*/

#include <stdio.h>

#define MAXSIZE 100
typedef int Elemtype;  //将int类型定义为Elemtype类型

typedef struct 
{
    Elemtype data[MAXSIZE]; 
    int length; //顺序表的当前长度
}SeqList;  //顺序表定义

typedef struct
{
    Elemtype *data; //指向顺序表数据元素的指针
    int length; //顺序表的当前长度
}SeqList2; //动态顺序表定义

//遍历顺序表
void listList(SeqList *L)
{
    for(int i = 0 ; i < L->length ; i++)
    {
        printf("%d  ", L->data[i]);
    }
    printf("\n");
}

//静态分配内存初始化顺序表
void initList(SeqList *L)
{
    L->length = 0;  //当前长度初始化为0
}

//动态分配内存初始化顺序表
SeqList2 * initList2(void)
{
    SeqList2 *L = (SeqList2 *)malloc(sizeof(SeqList2)); //分配内存空间
    L->data = (Elemtype *)malloc(sizeof(Elemtype) * MAXSIZE); //分配顺序表数据元素的内存空间
    L->length = 0; //当前长度初始化为0
    return L; //返回顺序表指针    
}

//在尾部添加元素
int appendElem(SeqList *L , Elemtype e)
{
    if(L->length >= MAXSIZE)  //判断顺序表是否已满
    {
        printf("顺序表已满\n");
        return -1; //返回-1表示添加失败
    }
    L->data[L->length] = e; //将元素添加到顺序表的末尾
    L->length++; //顺序表长度增加1
    return 0; //返回0表示添加成功
}

//指定位置插入元素
void insertElem(SeqList *L , int pos , Elemtype e)
{
    if(pos <= L->length-1 && pos >= 0) //判断插入位置是否合法
    {
        for(int i = L->length -1 ; i >= pos ; i--)
        {
            L->data[i+1] = L->data[i]; //将插入位置及其后面的元素向后移动一位
        }
        L->data[pos] = e; //将元素插入到指定位置
        L->length++; //顺序表长度增加1
    }
}

//查找元素
void findElem(SeqList *L , Elemtype e)
{
    int pos = -1; //定义一个变量用于保存查找结果，初始值为-1表示未找到
    for(int i = 0 ; i < L->length ; i++)
    {
        if(L->data[i] == e) //如果找到元素e
        {
            pos = i; //将元素e的位置保存到变量pos中
            break; //退出循环
        }
    }
    if(pos != -1)
    {
        printf("找到元素%d，位置为%d\n" , e , pos);
    }
    else
    {
        printf("未找到元素%d\n" , e);
    }
}

//删除元素
void deleteElem(SeqList *L , int pos , Elemtype *e)
{
    *e = L->data[pos]; //将要删除的元素保存到指针e所指向的内存中
    if(pos < 0 || pos >= L->length) //判断删除位置是否合法
    {
        printf("删除位置不合法\n");
        return; //返回表示删除失败
    }

    if (pos < L->length - 1) //如果删除位置不是最后一个元素
    {
        for(int i = pos ; i < L->length-1 ; i++)
        {
            L->data[i] = L->data[i+1]; //将删除位置后面的元素向前移动一位
        }
        L->length--; //顺序表长度减少1
    }
    else //如果删除位置是最后一个元素
    {
        L->length--; //顺序表长度减少1
    }

}

int main()
{
    //声明一个顺序表并初始化
    SeqList list;
    initList(&list);
    printf("当前顺序表的长度 = %d\n" , list.length);
    printf("当前顺序表占用%zu字节内存大小\n" , sizeof(list.data));
    appendElem(&list , 10);
    appendElem(&list , 20);
    appendElem(&list , 30);
    listList(&list); //输出顺序表中的元素
    insertElem(&list , 2 , 15); //在位置2插入元素15
    listList(&list); //输出顺序表中的元素
    insertElem(&list , 0 , 18); //在位置0插入元素18
    listList(&list); //输出顺序表中的元素
    int e; //声明一个变量用于保存删除的元素
    deleteElem(&list , 3 , &e); //删除位置3的元素，并将删除的元素保存到变量e中
    printf("删除的元素是  %d\n" , e);
    listList(&list); //输出顺序表中的元素
    findElem(&list , 30); //查找元素30

    SeqList2 * list2 = initList2(); //动态分配内存初始化顺序表
    printf("当前顺序表长度为 %d\n" , list2->length);
    printf("当前顺序表占用 %zu字节内存大小 \n" , sizeof(list2->data));
    listList2(list2); //输出顺序表中的元素
    return 0;
}
