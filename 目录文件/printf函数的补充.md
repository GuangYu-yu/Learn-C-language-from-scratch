# printf函数的补充

## 1.printf函数的含义

`printf`不是一个自定义函数，是一个`系统自带的函数`

printf由单词print（打印）和format（格式）而来，意思是格式化打印

printf函数的作用是将字符串输出到控制台上

## 2.printf函数的更多用法

printf是一个`变参函数`,可以接受可变数量和类型的输入参数。因此在”Hello World“只传了一个参数给printf，在add函数可以传两个给printf

打印一个整数（”666“）：

```
printf("%d",666);
```

打印两个整数

```
//printf("%d\n%d\n",整型int1,整型int2);
printf("A=%d\nB=%d\n",888,666);
```

其中`\n`表示换行，就是从下一行开始再继续打印

完整代码：

```
#include<stdio.h>
int main()
{
	printf("A=%d\nB=%d\n", 888, 666);
	return 0;
}
```

最终控制台显示：

```
A=888
B=666
```

printf的第一个参数必须是`字符串`，`%转换操作`用来占位，整型int的占位符为`%d`。后面的替换参数，会依次替换前面的占位。只要第一个字符串的参数占位符写对了，后面可以加任意数量的替换参数

[跳转至下一页]()

[返回目录](https://github.com/GuangYu-yu/Learn-C-language-from-scratch/blob/main/%E7%9B%AE%E5%BD%95%E6%96%87%E4%BB%B6/%E7%9B%AE%E5%BD%95.md)
