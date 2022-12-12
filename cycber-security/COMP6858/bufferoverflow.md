## BufferOverflow
====
***basic knowledge : assemble, understanding of virtual memory concept, gdb***

1. #### 什么是buffer
    buffer是一个连续的内存块，其中存储了多个相同数据类型的实例。例如，字符数组。数组和C中所有的变量一样，可以是静态和动态的。
    静态变量会在装入时在数据段分配空间，而动态变量则在运行时存储于栈中。

2. #### 进程在内存中的形式
    1. Text:包含代码和只读数据
    2. Data：包含初始化和未初始化的数据，静态变量存储于该区域。
    3. Stack：栈是一种计算机科学中常用的抽象数据类型，主要的性质为后进先出（LIFO）。栈定义了一系列操作方法，最主要的两个为push(),pop()，压栈和出栈操作。

                +-------------------+  low memory addresses
                |       Text        |
                +-------------------+
                |   (Initialized)   |
                |       Data        |
                |  (Uninitialized)  |
                +-------------------+
                |       Stack       |  higher memory addresses
                +-------------------+
3. #### 栈区
    栈是一个包含数据的连续内存块。在现代计算机系统中，许多高级语言需要结构化编程

