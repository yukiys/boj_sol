#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int T,H,W,ret;
char grid[102][102];
bool key[26];
bool visited[102][102];
vector<pair<int,int>> door[26];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void input()
{
    memset(grid,0,sizeof(grid));
    memset(key,0,sizeof(key));
    memset(visited,0,sizeof(visited));
    for(int i=0;i<26;i++) door[i].clear();
    ret=0;

    cin>>H>>W;

    for(int h=0;h<=H+1;h++)
    {
        for(int w=0;w<=W+1;w++)
        {
            if(h==0 or h==H+1 or w==0 or w==W+1) grid[h][w]='.';
            else cin>>grid[h][w];
        }
    }

    string str;
    cin>>str;
    if(str[0]!='0')
        for(char c:str)
            key[c-'a']=true;
}

void bfs(int a,int b)
{
    if(visited[a][b] or grid[a][b]=='*') return;
    visited[a][b]=true;

    queue<pair<int,int>> q;
    q.push({a,b});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 or nx>H+1 or ny<0 or ny>W+1 or grid[nx][ny]=='*' or visited[nx][ny]) continue;

            if('a'<=grid[nx][ny] and grid[nx][ny]<='z')
            {
                int k=grid[nx][ny]-'a';
                key[k]=true;
                grid[nx][ny]='.';
                visited[nx][ny]=true;
                q.push({nx,ny});
                
                for(int i=0;i<door[k].size();i++)
                {
                    int X=door[k][i].first;
                    int Y=door[k][i].second;
                    grid[X][Y]='.';
                    visited[X][Y]=true;
                    q.push({X,Y});
                }
                door[k].clear();
            }
            else if('A'<=grid[nx][ny] and grid[nx][ny]<='Z')
            {
                int d=grid[nx][ny]-'A';
                if(!key[d]) door[d].push_back({nx,ny});
                else
                {
                    grid[nx][ny]='.';
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
            else
            {
                if(grid[nx][ny]=='$') ret++;
                visited[nx][ny]=true;
                q.push({nx,ny});
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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>T;
    while(T--)
    {
        input();
        bfs(0,0);
        printResult();
    }

    return 0;
}