#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int I,y,x,B,A;
bool visited[300][300];
int dy[8]={-2,-1,1,2,2,1,-1,-2};
int dx[8]={1,2,2,1,-1,-2,-2,-1};

int bfs(int y,int x)
{
    visited[y][x]=true;
    queue<pair<int,int>> q;
    q.push({y,x});

    int ret=0;

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            int b=q.front().first;
            int a=q.front().second;
            q.pop();

            if(b==B and a==A) return ret;

            for(int j=0;j<8;j++)
            {
                int nb=b+dy[j];
                int na=a+dx[j];

                if(nb<0 or nb>=I or na<0 or na>=I) continue;
                if(!visited[nb][na])
                {
                    visited[nb][na]=true;
                    q.push({nb,na});
                }
            }
        }
        ret++;
    }

    return -1;
}

int main()
{
    int T; cin>>T;
    for(int t=0;t<T;t++)
    {
        cin>>I>>y>>x>>B>>A;
        memset(visited,false,sizeof(visited));

        cout<<bfs(y,x)<<"\n";
    }

    return 0;
}