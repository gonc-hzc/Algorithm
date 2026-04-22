#include <stdio.h>

//标准写法
typedef struct StructureName  //结构体标签名
{
    char data;
    struct  StructureName *p;
}SiteName;  //结构体别名

/*
只写前面，不写后面（不用typedef）
struct StructureName  //结构体标签名
{
    char data;
    struct  StructureName *p;  //标签名可以用来定义指针，且必须带上struct
}; 

这种写法定义变量必须加struct：struct StructureName a;
不能直接写：StructureName a；
*/

/*
只写后面，不写前面（匿名结构体）
typedef struct
{
    char data;
    //没有标签名不能自引用指针
}SiteName; 别名
*/


int main()
{
    return 0;
}