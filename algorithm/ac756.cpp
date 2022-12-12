#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    const int N =15;
    int map[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            map[i][j] = 0;
        }
    }
    int X[4] = {0,1,0,-1};
    int Y[4] = {1,0,-1,0};
    int x = 0,y = 0,step = 0;;
    for(int k=1;k<=m*n;k++)
    {
        map[x][y] = k;
        x+=X[step];
        y+=Y[step];
        if(x<0||x>=n||y<0||y>=m||map[x][y])
        {
            x-=X[step];
            y-=Y[step];
            step++;
            step=step%4;
            x+=X[step];
            y+=Y[step];
        }
        
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
