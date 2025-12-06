#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M,r,c,d,ret;
int grid[50][50];
pair<int,int> dir[4]={{-1,0},{0,1},{1,0},{0,-1}}; //북 동 남 서

void init()
{
    cin>>N>>M>>r>>c>>d;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>grid[i][j];
}

void bfs()
{
    queue<pair<int,int>> q;
    q.push({r,c});

    while(!q.empty())
    {
        int cr=q.front().first;
        int cc=q.front().second;
        q.pop();
        if(grid[cr][cc]==0)
        {
            ret++;
            grid[cr][cc]=-1;
        }

        bool check=false;
        for(int i=0;i<4;i++)
        {
            int nr=cr+dir[i].first;
            int nc=cc+dir[i].second;

            if(nr<0 or nr>=N or nc<0 or nc>=M or grid[nr][nc]==1) continue;
            
            if(grid[nr][nc]==0) check=true;
        }

        if(check)
        {
            for(int i=0;i<4;i++)
            {
                d=(d+3)%4;
                int nr=cr+dir[d].first;
                int nc=cc+dir[d].second;

                if(grid[nr][nc]==0)
                {
                    q.push({nr,nc});
                    break;
                }
            }
        }
        else
        {
            int t=(d+2)%4;
            int nr=cr+dir[t].first;
            int nc=cc+dir[t].second;

            if(grid[nr][nc]==1) return;

            q.push({nr,nc});
        }
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    init();
    bfs();
    printResult();
}