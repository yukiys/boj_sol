#include <iostream>

using namespace std;

int N,M,ret;
int grid[500][500];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N>>M;
    for(int n=0;n<N;n++)
        for(int m=0;m<M;m++)
            cin>>grid[n][m];

    for(int n=0;n<N;n++)
        for(int m=0;m+3<M;m++)
            ret=max(ret,grid[n][m]+grid[n][m+1]+grid[n][m+2]+grid[n][m+3]);
    
    for(int n=0;n+3<N;n++)
        for(int m=0;m<M;m++)
            ret=max(ret,grid[n][m]+grid[n+1][m]+grid[n+2][m]+grid[n+3][m]);

    for(int n=0;n+1<N;n++)
        for(int m=0;m+1<M;m++)
            ret=max(ret,grid[n][m]+grid[n][m+1]+grid[n+1][m]+grid[n+1][m+1]);
    
    for(int n=0;n<N;n++)
    {
        for(int m=0;m+2<M;m++)
        {
            int temp=grid[n][m]+grid[n][m+1]+grid[n][m+2];
            if(n==0) temp+=max(max(grid[n+1][m],grid[n+1][m+1]),max(grid[n+1][m+1],grid[n+1][m+2]));
            else if(n==N-1) temp+=max(max(grid[n-1][m],grid[n-1][m+1]),max(grid[n-1][m+1],grid[n-1][m+2]));
            else
            {
                int t=max(max(grid[n+1][m],grid[n+1][m+1]),max(grid[n+1][m+1],grid[n+1][m+2]));
                t=max(t,max(max(grid[n-1][m],grid[n-1][m+1]),max(grid[n-1][m+1],grid[n-1][m+2])));
                temp+=t;
            }
            ret=max(ret,temp);
        }
    }

    for(int n=0;n+2<N;n++)
    {
        for(int m=0;m<M;m++)
        {
            int temp=grid[n][m]+grid[n+1][m]+grid[n+2][m];
            if(m==0) temp+=max(max(grid[n][m+1],grid[n+1][m+1]),max(grid[n+1][m+1],grid[n+2][m+1]));
            else if(m==M-1) temp+=max(max(grid[n][m-1],grid[n+1][m-1]),max(grid[n+1][m-1],grid[n+2][m-1]));
            else
            {
                int t=max(max(grid[n][m+1],grid[n+1][m+1]),max(grid[n+1][m+1],grid[n+2][m+1]));
                t=max(t,max(max(grid[n][m-1],grid[n+1][m-1]),max(grid[n+1][m-1],grid[n+2][m-1])));
                temp+=t;
            }
            ret=max(ret,temp);
        }
    }

    for(int n=0;n+1<N;n++)
    {
        for(int m=0;m+2<M;m++)
        {
            int temp=grid[n][m+1]+grid[n+1][m+1];
            temp+=max(grid[n][m]+grid[n+1][m+2],grid[n+1][m]+grid[n][m+2]);
            
            ret=max(ret,temp);
        }
    }

    for(int n=0;n+2<N;n++)
    {
        for(int m=0;m+1<M;m++)
        {
            int temp=grid[n+1][m]+grid[n+1][m+1];
            temp+=max(grid[n][m]+grid[n+2][m+1],grid[n][m+1]+grid[n+2][m]);

            ret=max(ret,temp);
        }
    }

    cout<<ret<<"\n";

    return 0;
}