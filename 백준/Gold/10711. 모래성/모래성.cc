#include <iostream>
#include <queue>

using namespace std;

int H,W,ret;
int grid[1000][1000],cnt[1000][1000];
bool visited[1000][1000];
int dh[8]={-1,-1,-1,0,0,1,1,1};
int dw[8]={-1,0,1,-1,1,-1,0,1};
queue<pair<int,int>> q;

void init()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>H>>W;
    for(int h=0;h<H;h++)
    {
        for(int w=0;w<W;w++)
        {
            char c;
            cin>>c;
            if('1'<=c and c<='9')
                grid[h][w]=c-'0';
        }
    }

    for(int h=0;h<H;h++)
    {
        for(int w=0;w<W;w++)
        {
            if(grid[h][w]!=0) continue;
            
            for(int i=0;i<8;i++)
            {
                int nh=h+dh[i];
                int nw=w+dw[i];
                if(nh<0 or nh>=H or nw<0 or nw>=W) continue;

                if(grid[nh][nw]!=0)
                    cnt[nh][nw]++;
            }
        }
    }
}

void bfs()
{
    while(!q.empty())
    {
        int Size=q.size();
        ret++;

        for(int s=0;s<Size;s++)
        {
            int h=q.front().first;
            int w=q.front().second;
            q.pop();

            grid[h][w]=0;
            for(int i=0;i<8;i++)
            {
                int nh=h+dh[i];
                int nw=w+dw[i];
                if(nh<0 or nh>=H or nw<0 or nw>=W or grid[nh][nw]==0) continue;
                cnt[nh][nw]++;

                if(!visited[nh][nw] and grid[nh][nw]<=cnt[nh][nw])
                {
                    visited[nh][nw]=true;
                    q.push({nh,nw});
                }
            }
        }
    }
}

void solve()
{
    for(int h=1;h<H-1;h++)
    {
        for(int w=1;w<W-1;w++)
        {
            if(grid[h][w]!=0 and grid[h][w]<=cnt[h][w])
            {
                visited[h][w]=true;
                q.push({h,w});
            }
        }
    }
    
    bfs();
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}