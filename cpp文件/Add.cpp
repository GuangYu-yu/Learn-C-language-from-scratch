//引入头文件，printf在stdio.h文件被声明
#include <stdio.h>
//定义Add
int Add(int a,int b)
//返回相加的结果
{
	return a+b;
}
//主函数自动调用、返回值给调用的程序、主函数返回值必须为int
int main()
{
	//声明整型变量result
	int result;
	//将Add函数返回值存入变量result
	result=Add(2,3);
	//printf输出字符串，"%d"整型占位符
	printf("%d",result);
	//程序正常结束，返回值一般设为0
	return 0;
}
