# 数组模拟栈

**需要实现出栈入栈判空**

1. 初始化

    1. 创建数组
    2. 创建栈顶指针
```cpp
    const int N = 100010;
    int stk[N];
    int tt = 0;
```

2. 入栈

    1. 右移tt
    2. 将元素入栈
```CPP
    void push(int x)
    {
        stk[++tt] = x;
    }
```

3. 出栈
   
   1. tt--
```cpp
    int pop()
    {
        return stk[tt--];
    }
```

4. 判空
   1. 当栈顶指针小于等于0时栈为空
   ```cpp
    bool isempty()
    {
        if(t>0)return false;
        else return true;
    }
   ```