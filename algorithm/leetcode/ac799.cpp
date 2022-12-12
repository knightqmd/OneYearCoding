#include <iostream>
using namespace std;
const int N = 100010;
int q[N];
int main()
{
    int num,max=0;
    num = 100000;

    for(int i=0;i<num;i++)
    {
        q[i]=i;
    }
    for(int i=1,j=0;i<num;i++)
    {
        for(int k=j;k<i;k++)
        {
            if(q[k]==q[i])
            {
                j=k+1;
                break;
            }
        }
        max = (max<(i-j+1))?i-j+1:max;
    }
    cout<<max;
    return 0;
}

#include <iostream>
using namespace std;
const int N = 100010;
int q[N],s[N];
int main()
{
    int num,max=0;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>q[i];
    }
    for(int j=0,i=0;i<num;i++)
    {
        s[q[i]]++;
        if(s[q[i]]>1)
        {
            for(int k=j;k<i;k++)
            {
                s[q[k]]--;
                if(q[k]==q[i])
                {
                    j=k+1;
                    break;
                }
            }
        }
        max = (max<i-j+1)?i-j+1:max;
    }
    cout<<max;
    return 0;
}