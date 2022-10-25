# Buffer overflow attack 缓冲区溢出攻击

**Reference MIT 6.858 lec2 以下内容均为个人理解，不一定正确**
===
  21/10/2022  QIU MINGDON
===
## 什么是缓冲区溢出攻击
向运行中的程序的缓冲区内填入超出数量的数据，从而导致溢出的数据覆盖了合法数据。
```cpp
void read_req()
{
    char buf[128];
    int i;
    gets(buf);  
}
```
执行上述程序编译器生成的内存构成：
```
        +——————————————————+
        |     pre_frame    |
        +——————————————————+
        |     return addr  |
        +——————————————————+
        |     EBP          |
        +——————————————————+
        |     buf[127]     |
        |     ...          |
        |     buf[0]       |
        +——————————————————+
        |     i            | 
            函数栈（reaf_req）
```
**此次涉及函数调用相关的知识**
 ESP，EBP，其中E为extended表示扩展的。
 
 BP（基址寄存器）：该指针指向系统栈最上面一个栈帧的底部。 
 
 SP（栈寄存器）：用于存放函数栈顶指针。

***EP，SP都是存储的都是一个指针！！！*** 
===

 当进行函数调用时：
 1. 首先push EBP，即将EBP中的值压入栈中，如上图EBP所示位置。此举是为了保存之前函数的基址，当read_req()完成后，便于恢复现场。
 2. mov EBP, ESP  //将当前栈顶指针，保存到EBP寄存器中，从而确定了read_req()的基址位置。此时ESP与EBP值相等，而ESP为栈顶指针目前位于新建函数栈的最底端。
 3. 为各个变量分配存储空间，执行指令。
 4. 当函数执行完成后，需要恢复现场。
 5. mov esp, ebp  // 将ebp的值赋给esp，此时ebp内记录了read_req()的栈基址，也就是说将esp重新指向函数栈的底端。
 6. pop ebp  //将此时esp所指向的内存地址中的值出栈，并存如ebp（恢复了之前函数的基址）。
 7. ret  //执行返回指令，返回上一级函数调用该函数的位置。

===
如何利用以上过程进行缓冲区溢出攻击？

 - 提供一个很长的输入，超出栈中用于存放数据的buf
 - 1：攻击者可以选择覆写返回地址（return_addr），使程序跳转到攻击者想要的位置。
 - 2：攻击者可以将返回地址指向buffer本身，并在buffer里写上恶意代码。
===
会造成的后果
 - 可以使用进程的任何权限！如果进程以root身份运行或管理员，则可以在系统上为所欲为。

===
## 预防缓冲区溢出的方法

1. 避免C语言代码中的bug，使用相对安全的函数（例如用strncpy()代替strcpy(),fgets()代替gets()，scanf_s()代替scanf()等）。

2. 使用内存安全的语言例如JAVA，Python等。

3. 使用编译工具对代码进行检查。

## 减少缓冲区溢出的方法

1. canaries（金丝雀）:在被改写的代码指针被调用之前发现它。其思想是编译器在程序中安放canary变量，并检测canary变量是否被改写。类似用金丝雀在煤矿中检测一氧化碳 =)。
```
+——————————————————+
|  return address  |   
+——————————————————+    
|    saved %ebp    |   
+——————————————————+   
|     CANARY       |    
+——————————————————+   
| buf[127]         |    
|       ...        |    
|           buf[0] |
+——————————————————+ 
```
在返回地址前加上canaries，如果无法猜出canaries的值那么就无法改变函数的返回地址。
```cpp
void foo(const char* str)
{
	char buffer[16];
	strcpy(buffer, str);
}
```
SSP自动将上述代码转化：

``` c
extern uintptr_t __stack_chk_guard;
noreturn void __stack_chk_fail(void);
void foo(const char* str)
{
	uintptr_t canary = __stack_chk_guard;
	char buffer[16];
	strcpy(buffer, str);
	if ( (canary = canary ^ __stack_chk_guard) != 0 )
		__stack_chk_fail();
}
```
**然而canaries也可能不会被触发，导致该方法失效**
