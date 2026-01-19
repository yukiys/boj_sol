#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M,C,mst;
int grid[10][10];
bool visited[10][10];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<pair<int,int>> island[7];

int dist[7][7];
vector<pair<int,pair<int,int>>> V;
int parent[7];

int Find(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=Find(parent[a]);
}

void Union(int a,int b)
{
    a=Find(a);
    b=Find(b);
    if(a==b) return;

    if(a<b) parent[b]=a;
    else parent[a]=b;
}

void checkIsland(int a,int b)
{
    if(visited[a][b] or grid[a][b]==0) return;

    C++;
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b]=true;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        grid[x][y]=C;
        island[C].push_back({x,y});

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 or nx>=N or ny<0 or ny>=M or visited[nx][ny] or grid[nx][ny]==0) continue;

            q.push({nx,ny});
            visited[nx][ny]=true;
        }
    }
}

void getDist()
{
    for(int c=1;c<=C;c++)
    {
        for(int i=0;i<island[c].size();i++)
        {
            int x=island[c][i].first;
            int y=island[c][i].second;

            for(int nx=x-1;nx>=0;nx--)
            {
                int next=grid[nx][y];
                if(next==c) break;
                if(next==0) continue;
                
                int len=abs(x-nx)-1;
                if(len<=1) break;
                dist[c][next]=dist[next][c]=min(dist[c][next],len);
                break;
            }

            for(int nx=x+1;nx<N;nx++)
            {
                int next=grid[nx][y];
                if(next==c) break;
                if(next==0) continue;
                
                int len=abs(x-nx)-1;
                if(len<=1) break;
                dist[c][next]=dist[next][c]=min(dist[c][next],len);
                break;
            }

            for(int ny=y-1;ny>=0;ny--)
            {
                int next=grid[x][ny];
                if(next==c) break;
                if(next==0) continue;
                
                int len=abs(y-ny)-1;
                if(len<=1) break;
                dist[c][next]=dist[next][c]=min(dist[c][next],len);
                break;
            }

            for(int ny=y+1;ny<M;ny++)
            {
                int next=grid[x][ny];
                if(next==c) break;
                if(next==0) continue;
                
                int len=abs(y-ny)-1;
                if(len<=1) break;
                dist[c][next]=dist[next][c]=min(dist[c][next],len);
                break;
            }
        }
    }
}

void init()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>grid[i][j];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            checkIsland(i,j);

    for(int i=1;i<=C;i++)
        parent[i]=i;

    for(int i=1;i<=C;i++)
        for(int j=1;j<=C;j++)
            if(i!=j)
                dist[i][j]=11;
    getDist();

    for(int i=1;i<=C;i++)
        for(int j=1;j<=C;j++)
            if(i<j and dist[i][j]!=11)
                V.push_back({dist[i][j],{i,j}});
    sort(V.begin(),V.end());
}

void Kruskal()
{
    int cnt=0;
    for(int i=0;i<V.size();i++)
    {
        int cost=V[i].first;
        int now=V[i].second.first;
        int next=V[i].second.second;

        if(Find(now)==Find(next)) continue;
        
        cnt++;
        Union(now,next);
        mst+=cost;

        if(cnt==C-1) return;
    }

    mst=-1;
}

void printRet()
{
    cout<<mst<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    Kruskal();
    printRet();
}