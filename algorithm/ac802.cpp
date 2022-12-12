#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find(int x,vector<pair<long,int>>& alls)
{
    int l=0,r=alls.size()-1;
    int mid;
    while(l<r)
    {
        mid = l+r>>1;
        if(alls[mid].first>=x)r=mid;
        else
        {
            l=mid+1;
        }
    }
    if(alls[r].first<x)return r+1;
    return r;
}

int main()
{
    const int N =100010;
    int m,n;
    cin>>n>>m;
    vector<pair<long,int>> arr;
    for(int i=0;i<n;i++)
    {
        pair<long,int> temp;
        cout<<i<<endl;
        cin>>temp.first>>temp.second;
        arr.push_back(temp);
    }
    int lop[N];
    int rop[N];
    for(int k=0;k<m;k++)
    {
        cin>>lop[k]>>rop[k];
    }

    for(int i=0;i<m;i++)
    {
        bool flag = true;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j].first==lop[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)arr.push_back(make_pair(lop[i],0));
        flag = true;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j].first==rop[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)arr.push_back(make_pair(rop[i],0));
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<m;i++)
    {
        int l_index = lop[i];
        int r_indxe = rop[i];
        int sum=0;
        l_index = find(l_index,arr);
        r_indxe = find(r_indxe,arr);
        for(int j=l_index;j<=r_indxe;j++)
        {
            sum+=arr[j].second;
        }
        cout<<sum<<endl;
    }
    return 0;
}