#include<iostream>
using namespace std;

int const N = 100010;
int q[N];
//定义队头队尾
int hh,tt;

void init()
{
    hh = 0;
    tt = -1;
}
void push(int x)
{
    q[++tt] = x;
}
int  pop()
{
    hh++;
    return q[hh-1];
}
void show()
{
    for(int i = hh;i<=tt;i++)
    {
        cout<<q[i]<<" ";
    }
    cout<<endl;
}
bool isempty()
{
    if(tt<hh)return true;
    else
    {
        return false;
    }
}
void test()
{
    init();
    push(1);
    show();
    push(2);
    show();
    pop();
    show();
    push(3);
    show();
    cout<<isempty()<<"  isempty was called"<<endl;
    int y = pop();
    cout<<" y = "<<y<<endl;
    pop();
    cout<<"isempty was called: "<<isempty()<<endl;
}
int main()
{
    test();
    return 0;
}
