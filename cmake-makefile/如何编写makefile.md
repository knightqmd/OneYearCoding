#   makefile介绍
当我们执行make命令对项目进行编译时，需要一个makefile文件来指导make命令对源程序进行编译和链接

##  makefile的规则
> target ... : prerequisites ...
>   command

**target**
    可以是目标文件，也可以是一个执行文件，也可以是一个标签
**prerequisites**
    生成target所需要的依赖文件
**command**
    shell命令（生成该target需要执行的命令）

