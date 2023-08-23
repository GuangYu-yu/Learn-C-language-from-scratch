# printf函数详解

## 1.长度指示符

```
#include <stdio.h>
int main()
{
long l = 2147483647;
long long ll = 9223372036854775807;
printf("%d\n", l);
printf("%d\n", ll);
return 0;
}
```

```
2147483647
-1
```

sizeof(long long)比sizeof(int)长得多，所以变量 ll 被错误输出

要正常输出long long数据类型，必须加宽转换操作获取的二进制数据长度

在转换操作前增加一个 h 或 l 长度指示符，可以将转换操作获取的二进制长度降低或提升一级的类型长度

|长度指示符|转换操作|二进制字节长度n|
|-|-|-|
|l |d或i |sizeof(long)|
|ll |d或i |sizeof(long long)|
|l |u或o或x或X |sizeof(unsigned long)|
|ll |u或o或x或X |sizeof(unsigned long long)|
|h |d或i |sizeof(short)|
|hh |d或i |sizeof(char)|
|h |u或o或x或X |sizeof(unsigned short)|
|hh |u或o或x或X |sizeof(unsigned char)|

```
#include <stdio.h>
int main()
{
unsigned int un = 0x12345678;//0x是十六进制数的前缀
printf("%hX\n", un); // h将X获取的二进制数据长度加缩短sizeof(unsigned short)
printf("%hhX\n", un); // hh将X获取的二进制数据长度缩短到sizeof(unsigned char)
return 0;
}
```

```
5678
78
```

z 长度指示符，用于指示类型 size_t 的长度
关键字 sizeof 返回的结果就是 size_t 类型的，而 size_t 并不是一个新的关键字，它是已有整型变量的别名。它有可能是 unsigned int 别名,也有可能是 unsigned long 或 unsigned long long 的别名,取决于
编译器怎样实现

```
printf("%zu\n", sizeof(int));
```

**对 size_t 类型使用 %zu 转换规范才是严谨的**

## 2.精度

```
#include <stdio.h>
int main()
{
int un = 123;
double df = 123.456789;
printf("%.6d\n", un); // 限制为6个最小数字位数，所以前面添加了0，补到6个数字。
printf("%f\n", df); // 不限制小数点后的数字个数
printf("%.0f\n", df); // 小数点后的数字个数限制为0，小数点后无数字。
printf("%.4f\n", df); // 小数点后的数字个数限制为4，小数点后跟了4个数字。
return 0;
}
```

```
000123
123.456789
123
123.4568
```

## 3.最新字段宽度

```
#include <stdio.h>
int main()
{
int un = 1234;
double df = 123.456789;
printf("%2d\n", un); // 最小要求2位，有4位，不做处理。
printf("%6d\n", un); // 只有4位，补齐到6位。
printf("%12f\n", df); // 只有10位，补齐到12位。
return 0;
}
```

```
1234
  1234
  123.456789
```

最小字段宽度指定输出的字符最最小字符数量，如果不足，将使用空格补齐到指定的最小宽度

## 4.标志

标志 0 使用0而不是空格作为填充字符

标志 - 打印的字符左对齐

标志 + 总是产生符号，正号或者负号

标志 # 八进制前加0，十六进制前加0x

```
#include <stdio.h>
int main()
{
int n = 6666;
printf("%6d\n", n); // 只有4位，使用空格，补齐到6位。
printf("%06d\n", n); // 只有4位，使用字符0，补齐到6位。
printf("%-6d\n", n);
printf("%-06d\n", n);
printf("%+6d\n", n);
printf("%+06d\n", n);
printf("%#o\n", n);
printf("%#X\n", n);
return 0;
}
```

```
  6666
006666
6666
6666
 +6666
+06666
015012
0X1A0A
```

## 5.深入printf

十进制2147483647，正数的补码为它本身的二进制。所以，其补码
为 

|01111111|11111111|11111111|11111111|
|-|-|-|-|

类型为int，进入printf函数后，类型并不会发生转换，仍然为4个字节

使用 %u 来做转换规范时，$\underline{\text{printf会获取4字节的数据，并认为其为无符号整数}}$。它没有符号位，因此肯定为一个正数的补码。可以直接将它转换为十进制，转换结果为字符串"2147483647"

使用 %d 来做转换规范时，$\underline{\text{printf会获取4字节的数据，并认为其为有符号整数}}$。最高位看做符号位，其余为数据位。而在这个二进制中最高位为0，因此它是一个正数的补码，可以直接将它转换为十进制，转换结果为字符串"2147483647"

在这种情况下，使用 %u 或 %d 均可以得到正确的转换结果

由于， 以%开始的一串字符 指示printf函数如何转换二进制数据，所以将其称为转换规则更为准确

当

|11111111|11111111|11111111|11111111|
|-|-|-|-|

进入printf函数后

使用 %u 来做转换规范时，printf会获取4字节的数据，并认为其为无符号整数。它没有符号位，因此肯定为一个正数的补码。可以直接将它转换为十进制，转换结果为4294967295

使用 %d 来做转换规范时，printf会获取4字节的数据，并认为其为有符号整数。最高位看作符号位，其余为数据位。而在这个二进制中最高位为1，因此它是某一个负数的补码，设这个负数为n。

补码的计算规则：若 n 为负数，设 dec = mod - |n| ， n 的补码为 dec 的二进制

>mod(模)、dec（十进制）

n 的补码为 11111111 11111111 11111111 11111111 ，则dec为4294967295

四个字节的二进制可以表示$2^{32}$个数值，mod为$2^{32}$=4294967296

mod - |n| = dec，则4294967296 - |n| = 4294967295，n为-1

综上，只有数值的二进制中的最高位是“0”，使用%d或%u才能得到正确的转换结果，因此需严格使用类型对应的转换规范

## 6.长度造成的转换规范与参数不匹配

```
#include <stdio.h>
int main()
{
unsigned long l = 4294967295;
unsigned long long ll = 18446744073709551615;
printf("%u\n", l);
printf("%u %u\n", ll);
return 0;
}
```

```
4294967295
4294967295 4294966655
```

给 unsigned long 和 unsigned long long 分别初始化为它们所能表示的最大值，使得二进制中每一个位均为1

接着用转换规范 %u 把它们看做无符号整数来打印它们

在第一个printf函数中，变量l被正确打印了

而在第二个printf函数中，第一个 %u 获取并打印了ll的4个字节，第二个 %u 获取并打印了ll的另外4个字节

unsigned long 和 unsigned long long 均为比 unsigned int 高级的类型，因此它们进入printf函数的时候仍然保持有类型。但是转换规范 %u 或 %d ，它们仅仅取了int或unsigned int类型的大小，也就是4个字节进行转换

由于 unsigned long 在Visual Studio中也是4个字节，所以结果正确。而unsigned long long 在Visual Studio中为8个字节，因此数据被截断了一半

可以看出：转换规范 与 参数 并不是一一对应的，它需要程序员精确地设置转换规范，使其保持对应关系

要改变转换规范获取的字节长度，则需要在转换规范中添加长度指示符:

```
#include <stdio.h>
int main()
{
	unsigned long long n = 18446744073709551615;
	printf("%llu\n", n);
	return 0;
}
```

## 7.缩短转换数据字节长度

```
#include <stdio.h>
int main()
{
unsigned int n1 = 4294967295;
unsigned int n2 = 1234567890;
printf("%hu %u", n1, n2);
return 0;
}
```

```
65535 1234567890
```

长度指示符 h、hh 是通过先获取原有长度的数据，再丢弃一部分数据，从而达到缩短转
换数据长度的

|~~11111111~~|~~11111111~~|11111111|11111111|
|-|-|-|-|

>第一个 %hu ，根据 u 获得了n1的4个字节，而 h 导致其丢弃了已经获取的2字节

|01001001|10010110|00000010|11010010|
|-|-|-|-|

>第二个 %u 正常获得了n2的4个字节