# printf函数详解

1.printf函数的使用

`printf("xx占位1 xx占位2 xx占位3"),替换1,替换2,替换3;`

结论：

printf是一个变参函数

printf的第一个参数是字符串

printf的第一个参数是需要输出的字符，以及需要被替换的占位符

printf从第二个参数开始，将依次替换占位符

占位符的类型和数量需要跟后续的参数类型和数量对应

## 2.整型类型的占位符

printf是一个可变参数函数，在C语言中将参数传入函数的可变参数中，变量会发生自动类型提升

### 有符号整型的类型提升

char、short，传入printf的可变参数时，会被提升为int，比int更高级的整型则不会发生变化

因此，char、short、int均可使用%d来占位

为了程序的可移植性，在切换到别的平台时，int和long可能会不一致。因此即便int和long范围一致，最好使用`%ld`来占位。long long使用`%lld`来占位

### 无符号整型的类型提升

unsigned char、unsigned short传入printf的可变参数时，会被提升为unsigned int，而比unsigned int更高级的整型则不会发生变化

对于无符号的整型，将d替换为u表面最高位不看作符号位：

|unsigned char|unsigned short|unsigned int|
|-|-|-|
|%u|%lu|%llu|

###浮点类型的类型提升

float、double均使用%f

## 3.转换规范

转换规范以百分号开始依次跟着：

* 零个或多个**标志**字符：-、+、0、#
* 一个可选的十进制常量表示的**最小字段宽度**
* 一个可选的用点号表示**精度**范围，它的后面跟着一个十进制整数
* 一个可选的**长度指示符**，可用h、hh、l、LL、z组合之一来表示
* 由单个字符表示的**转换操作**，c、d、e、E、f、i、o、s、u、x、X

|以%开始|标志|最小字段宽度|精度|长度指定符|转换操作|
|-|-|-|-|-|-|
|%|-#0|12|.4|l|d|

### 转换操作

printf可以根据**转换操作**使用不同的转换方式，取n字节的二进制数据并转换成字符

|转换操作|二进制字节长度n|转换方式|
|-|-|-|
|c|sizeof(int)|数值对应的ASCII字符|
|d|sizeof(int)|有符号十进制整型|
|e|sizeof(double)|双精度浮点型，e计数法表示|
|E|sizeof(double)|双精度浮点型，E计数法表示|
|f|sizeof(double)|双精度浮点型，十进制浮点数|
|i|sizeof(int)|与d相同|
|o|sizeof(unsigned int)|无符号八进制整型|
|s|sizeof(char *)|字符串|
|u|sizeof(unsigned int)|无符号十进制整型|
|x|sizeof(unsigned int)|无符号十六进制整型|
|X|sizeof(unsigned int)|无符号十六进制整型|

---

#### 转换操作——d

```
#include <stdio.h>
int main()
{
char c1 = 127;
short s1 = 32767;
int n1 = 2147483647;
char c2 = -128;
short s2 = -32768;
int n2 = -2147483648;
printf("%d\n", c1);
printf("%d\n", s1);
printf("%d\n", n1);
printf("%d\n", c2);
printf("%d\n", s2);
printf("%d\n", n2);
return 0;
}
```

比int低级的整型类型，在进入printf时会转换为int

---

#### 转换操作——u

```
#include <stdio.h>
int main()
{
unsigned char c1 = 0;
unsigned short s1 = 0;
unsigned int n1 = 0;
unsigned char c2 = 255;
unsigned short s2 = 65535;
unsigned int n2 = 4294967295;
printf("%u\n", c1);
printf("%u\n", s1);
printf("%u\n", n1);
printf("%u\n", c2);
printf("%u\n", s2);
printf("%u\n", n2);
return 0;
}
```

比unsigned int低级的整型类型,在进入printf时会转换为unsigned int

---

### 交换转换操作

有符号整型int与无符号整型int的取值范围不一致，错误搭配可能造成错误的转换结果

int的取值范围为-2147483648~2147483647

unsigned int的取值范围为0~4294967295

交集为0~2147483647

```
#include <stdio.h>
int main()
{
int n = 2147483647;
unsigned int u = 2147483647;
// n
printf("n = %d\n", n);
printf("n = %u\n", n);
// u
printf("u = %d\n", u);
printf("u = %u\n", u);
return 0;
}
```

运行后发现：在交集内两种转换都能得到正确结果

如果不在交集内：

```
#include <stdio.h>
int main()
{
int n = -1;
unsigned int u = 4294967295;
// 打印n
printf("n=%d\n", n);
printf("n=%u\n", n);
// 打印u
printf("u=%d\n", u);
printf("u=%u\n", u);
return 0;
}
```

运行结果为：

```
n=-1
n=4294967295
u=-1
u=4294967295
```

-1为有符号整型int的取值范围，使用 d 可以正常打印，而 u 却出错

4294967295为无符号整型unsigned int的取值范围，使用 u 可以正常打印，而 d 却出错

**因此，为了保证转换正确，需`严格使用`与类型对应的转换操作**

运行：

```
#include <stdio.h>
int main()
{
char c = 128;
unsigned short s = -1;
int n = 2147483648;
printf("c=%d\n", c);
printf("s=%d\n", s);
printf("n=%d\n", n);
printf("c=%u\n", c);
printf("s=%u\n", s);
printf("n=%u\n", n);
return 0;
}
```

结果：

```
c=-128
s=65535
n=-2147483648
c=4294967168
s=65535
n=2147483648
```

初始化的值均超过了它们可以容纳的数值范围，因此无法得到正确的结果

---

#### 转换操作——c

运行：

```
#include <stdio.h>
int main()
{
char c = 65;
short s = 66;
int n = 67;
printf("c=%d\n", c);
printf("s=%d\n", s);
printf("n=%d\n", n);
printf("c=%c\n", c);
printf("s=%c\n", s);
printf("n=%c\n", n);
return 0;
}
```

结果：

```
c=65
s=66
n=67
c=A
s=B
n=C
```

比int低级或等于的整型类型，在进入printf时会转换为int。因此使用转换操作c，取sizeof(int) 字节二进制数据，将数值转换为数值对应的ASCII字符并打印在控制台上。

#### 转换操作——f

变量f, df 分别是double低级或等于的整型类型，进入printf时会转换为double

因此使用转换操作f，取 sizeof(double) 字节二进制数据，并将它们按照双精度浮点型转换为字符并打印在控制台上

#### 转换操作——e、E

转换操作e，E与f类似，但是使用e计数法。e与E的只有大小写的区别

#### 转换操作——x、X

x和X只有大小写的区别

#### 转换操作——s

```
#include <stdio.h>
int main()
{
printf("%s", "Hello World\n");
return 0;
}
```

```
Hello World

```

s 转换操作，将获取 sizeof(char *) 字节二进制数据，并将这个数据看作字符串首地址，从首地址开始，输出这串字符串

[跳转至下一页](https://github.com/GuangYu-yu/Learn-C-language-from-scratch/blob/main/%E7%9B%AE%E5%BD%95%E6%96%87%E4%BB%B6/printf%E5%87%BD%E6%95%B0%E8%AF%A6%E8%A7%A32.md)

[返回目录](https://github.com/GuangYu-yu/Learn-C-language-from-scratch/blob/main/%E7%9B%AE%E5%BD%95%E6%96%87%E4%BB%B6/%E7%9B%AE%E5%BD%95.md)
