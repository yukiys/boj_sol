#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N,M;
int grid[100][100];
int visited[100][100];
int dm[4]={-1,1,0,0};
int dn[4]={0,0,-1,1};
int ret=0,ret1,ret2,ret3,check;

void input()
{
    cin>>N>>M;
    for(int m=0;m<M;m++)
        for(int n=0;n<N;n++)
            cin>>grid[m][n];
}

bool bfs(int a,int b)
{
    visited[a][b]=true;
    queue<pair<int,int>> q;
    q.push({a,b});
    while(!q.empty())
    {
        int m=q.front().first;
        int n=q.front().second;
        q.pop();
        if(m==M-1) return true;

        for(int i=0;i<4;i++)
        {
            int nm=m+dm[i];
            int nn=n+dn[i];

            if(nm<0 or nm>=M or nn<0 or nn>=N or visited[nm][nn]) continue;
            if(grid[nm][nn]!=ret1 and grid[nm][nn]!=ret2 and grid[nm][nn]!=ret3) continue;
            
            visited[nm][nn]=true;
            q.push({nm,nn});
        }
    }
    return false;
}

void solve()
{
    while(ret<1000 and check!=1)
    {
        ret1=ret/100;
        ret2=(ret%100)/10;
        ret3=ret%10;
        ret++;

        for(int n=0;n<N;n++)
        {
            memset(visited,0,sizeof(visited));

            if(grid[0][n]==ret1 or grid[0][n]==ret2 or grid[0][n]==ret3)
            {
                if(bfs(0,n))
                {
                    check=1;
                    break;
                }
            }
        }
    }
}

void printResult()
{
    if(check==1) cout<<ret1<<" "<<ret2<<" "<<ret3<<"\n";
    else cout<<"-1 -1 -1"<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}