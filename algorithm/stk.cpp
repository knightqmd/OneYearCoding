#include<iostream>
using namespace std;

const int N = 100010;

int stk[N];
int tt = 0;
void push(int x)
{
    stk[++tt] = x;
}

int  pop()
{
    return stk[tt--];
}

bool isempty()
{
    if(tt>0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void show()
{
    for(int i = 1;i<=tt;i++)
    {
        cout<<stk[i]<<" ";
    }
    cout<<endl;
}

void test()
{
    push(4);
    push(5);
    show();
    int y = pop();
    cout<<"y = "<<y<<endl;
    show();
    push(6);
    show();
    cout<<isempty()<<endl;
    pop();
    show();
    pop();
    cout<<isempty()<<endl;
}
int main()
{
    test();
    return 0;   
}