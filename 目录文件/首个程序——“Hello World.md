# **首个程序——“Hello World”**

## 1.创建项目

### 直接创建新项目

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E6%96%B0%E5%BB%BA%E9%A1%B9%E7%9B%AE.png)

***或者***

### 从继续但无需代码来新建项目

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E6%96%B0%E5%BB%BA%E9%A1%B9%E7%9B%AE%E7%9A%84%E5%8F%A6%E4%B8%80%E7%A7%8D%E6%96%B9%E5%BC%8F.png)

## 2.选择项目类型

选择控制台应用

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E9%80%89%E6%8E%A7%E5%88%B6%E5%8F%B0%E5%BA%94%E7%94%A8.png)

## 3.给项目命名，并指定保存位置

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E7%BB%A7%E7%BB%AD%E6%96%B0%E5%BB%BA%E9%A1%B9%E7%9B%AE.png)

## 4.删除示例并创建源文件

从解决方案资源管理器删除示例

> 一般Visual Studio（**简称VS**）的新项目默认创建示例文件，由于要自己编写"Hello World"程序，因此要删除默认示例文件

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E5%88%A0%E9%99%A4%E7%A4%BA%E4%BE%8B%E6%96%87%E4%BB%B6.png)

创建新的源文件

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E5%88%9B%E5%BB%BA%E6%96%B0%E7%9A%84%E6%BA%90%E6%96%87%E4%BB%B6.png)

新建cpp文件

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E6%96%B0%E5%BB%BAcpp%E6%96%87%E4%BB%B6.png)

> `.c`和`.cpp`分别是C和C++语言的文件后缀，C++兼容C语言的大部分语法，一般C++源文件编译C语言代码是没有问题的，这是C++兼容C做的设计，`.c`作为后缀也是可以的，但无法使用C++的语法

## 5.输入“Hello World”

[跳转至cpp文件](https://github.com/GuangYu-yu/Learn-C-language-from-scratch/blob/main/cpp%E6%96%87%E4%BB%B6/HelloWord.cpp)

> 不建议直接复制代码，试着手动输入

```
#include <stdio.h>
int main()
{
	printf("Hello Word");
	return 0;
}
```

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E8%BE%93%E5%85%A5%E4%BB%A3%E7%A0%81.png)

## 6.编译并运行项目

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E7%BC%96%E8%AF%91%E4%BB%A3%E7%A0%81%E5%B9%B6%E8%BF%90%E8%A1%8C.png)

> 下方输出可以看到编译成功。如果有错误或警告，则可能是输入有误，注意文本和符号均采用英文输入。

## 7.运行程序

![](https://raw.githubusercontent.com/GuangYu-yu/Learn-C-language-from-scratch/main/%E5%BC%95%E7%94%A8%E7%9A%84%E5%9B%BE%E7%89%87/%E9%A6%96%E4%B8%AA%E7%A8%8B%E5%BA%8F%E2%80%94%E2%80%94%E2%80%9CHello%20World%E2%80%9D/%E8%BF%90%E8%A1%8C%E7%A8%8B%E5%BA%8F.png)

> 正确输入并运行后可以看到"Hello World"在控制台中被正确打印出来

[跳转至下一页](https://github.com/GuangYu-yu/Learn-C-language-from-scratch/blob/main/%E7%9B%AE%E5%BD%95%E6%96%87%E4%BB%B6/%E5%9F%BA%E7%A1%80%E8%AF%AD%E6%B3%95.md)

[返回目录](https://github.com/GuangYu-yu/Learn-C-language-from-scratch/blob/main/%E7%9B%AE%E5%BD%95%E6%96%87%E4%BB%B6/%E7%9B%AE%E5%BD%95.md)
