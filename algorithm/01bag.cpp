// #include<iostream>
// using namespace std;

// int main()
// {
//         const int N = 101;
//     int num,V;
//     int ws[N],vs[N];
//     cin>>num>>V;
//     // for(int i=0;i<num;i++)
//     // {
//     //     dp[i][0]=0;
//     // }
//     // for(int i=0;i<V;i++)
//     // {
//     //     dp[0][i]=0;
//     // }

//     int dp[N][N];
//     for(int i=1;i<=num;i++)
//     {
//         cin>>vs[i]>>ws[i];
//     }
//     for(int i=1;i<=num;i++)
//     {
//         for(int j=1;j<=V;j++)
//         {
//             if(j-vs[i]<0)
//             {
//                 dp[i][j] = dp[i-1][j];

//             }
//             else{
//                 dp[i][j]=max(dp[i-1][j],dp[i-1][j-vs[i]]+ws[i]);
               
//             }
//              cout<<dp[i][j]<<"  ";
//         }
//         cout<<endl;
//     }
//     cout<<dp[num][V];
//     return 0;
    
// }
#include <iostream>
using namespace std;
const int N =1020;
int dp[N][N];
int vs[N],myws[N];

int main()
{
    int num,size;
    cin>>num>>size;
    for(int i=1;i<=num;i++)
    {
        cin>>vs[i]>>myws[i];
    }
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=size;j++)
        {
            if(j<vs[i])dp[j][i]=dp[j][i-1];
            else
            {
                dp[j][i]=max(dp[j][i-1],dp[j-vs[i]][i-1]+myws[i]);
            }
        }
    }
    printf("%d",dp[size][num]);
    return 0;
}