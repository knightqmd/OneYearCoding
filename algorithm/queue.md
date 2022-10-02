# 队列
使用数组模拟队列
**需要实现队列的插入删除判空操作**

1.创建队列

    1.初始化列表
    2.创建队头指针(只在第一个元素位置)
    3.创建队尾指针(未添加元素时应指在-1)
```cpp
    const int N = 100010;
    int hh = 0,tt = -1;
```
2.入队

    1.入队时队尾指针右移
    2.加入元素
```cpp
    void push(int x)
    {
        q[++tt] = x;
    }
```
3.出队

    1.队头右移
    2.弹出前一个元素
```cpp
int pop()
{
    hh++;
    return[hh-1];
}
```

4.判空

    1.当队尾小于队头时为空
```cpp
    bool isempty()
    {
        if(tt<hh)return true;
        else return false;
    }
```