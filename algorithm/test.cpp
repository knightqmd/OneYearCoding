#include<iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
const int N =100010;
void bincout(int x)
{
    //二进制输出一个数
    cout<<"binary:";
    for(int i=63;i>=0;i--)
    {
        cout<<((x>>i)&1);
        if(i==32)cout<<"  ";
    }
}
int* unique(int a[],int n)
{
    //元素去重
    /***
    int a[N] = {1,1,2,2,3,4,5,0,0,77,7,7,7,9,9,10};
    int* b;
    b = unique(a,16);
    for(int i=0;i<16;i++)
    {
        cout<<b[i]<<" ";
    }
    delete b; 
    ***/
    sort(a,a+n);
    int *p = new int[n];
    int i=0,j=0,index = 0;
    while(j<n)
    {
        while(a[i] == a[j])
        {
            j++;
        }
        p[index] = a[i];
        index++;
        i=j;
    }
    return p;
}

int find(int x,vector<int>& alls)
{
    /***
    二分查找
    vector<int> alls = {1,3,5,11,22,41,100};
    int x = 11;
    cout<<find(x,alls)<<endl;
    */
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid = l+r>>1;
        if(alls[mid]>=x)r=mid;
        else l=mid+1;
    }
    return r;
}

int main()
{

    return 0;
}