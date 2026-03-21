//用字符型的数组表示字符串
#include <stdio.h>
#include <string.h>  //当用关于字符串函数时，需要包含该头文件

int main()
{
    char str[] = "hello world";  //字符串末尾隐藏 \0

    //错误写法
    //char str2[12];
    //str2[12] = "hello world";

    char str2[11];
    strcpy(str2 , "HelloWorld"); //strcpy()给字符型数组赋值的的函数

    printf("str = %s\n",str);
    printf("str2 = %s\n",str2);
    return 0;
}