#include<iostream>
using namespace std;
int main()
{
    char x[1024] = {1};
    for(int i =0 ; i<1024;i++)
    {
        x[i] = i;
    }
    char* y = &x[107];
    int* ptr;
    cout<<"size of ptr"<<sizeof(ptr)<<endl;
    cout<<sizeof(y)<<endl;
    cout<<"y:"<<y<<endl;
    cout<<"*y:"<<*y<<endl;
    return 0;
}