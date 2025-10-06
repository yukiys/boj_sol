#include <iostream>
#include <queue>

using namespace std;

int N,M,ret=-1;
char grid[10][10];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
int visited[10][10][10][10];

struct INFO
{
    int rr,rc;
    int br,bc;
    int count;
};
INFO start;

void input()
{
    cin>>N>>M;
    for(int r=0;r<N;r++)
    {
        for(int c=0;c<M;c++)
        {
            cin>>grid[r][c];
            if(grid[r][c]=='R')
            {
                start.rr=r;
                start.rc=c;
                grid[r][c]='.';
            }
            if(grid[r][c]=='B')
            {
                start.br=r;
                start.bc=c;
                grid[r][c]='.';
            }
        }
    }
}

pair<int,int> roll(int r,int c,int dir)
{
    while(1)
    {
        if(grid[r][c]=='O') break;

        int nr=r+dr[dir];
        int nc=c+dc[dir];
        if(grid[nr][nc]=='#') break;

        r=nr;
        c=nc;
    }

    return {r,c};
}

void bfs(INFO start)
{
    queue<INFO> q;
    q.push(start);
    visited[start.rr][start.rc][start.br][start.bc]=true;

    while(!q.empty())
    {
        INFO cur=q.front();
        q.pop();

        if(grid[cur.rr][cur.rc]=='O' and grid[cur.br][cur.bc]!='O')
        {
            ret=cur.count;
            break;
        }

        for(int i=0;i<4;i++)
        {
            auto [nrr,nrc]=roll(cur.rr,cur.rc,i);
            auto [nbr,nbc]=roll(cur.br,cur.bc,i);

            if(grid[nbr][nbc]=='O') continue;

            if(nrr==nbr and nrc==nbc)
            {
                int rDist=abs(cur.rr-nrr)+abs(cur.rc-nrc);
                int bDist=abs(cur.br-nbr)+abs(cur.bc-nbc);

                if(rDist<bDist)
                {
                    nbr-=dr[i];
                    nbc-=dc[i];
                }
                else
                {
                    nrr-=dr[i];
                    nrc-=dc[i];
                }
            }

            if(!visited[nrr][nrc][nbr][nbc] and cur.count<10)
            {
                q.push({nrr,nrc,nbr,nbc,cur.count+1});
                visited[nrr][nrc][nbr][nbc]=true;
            }
        }
    }
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    bfs(start);
    printResult();

    return 0;
}