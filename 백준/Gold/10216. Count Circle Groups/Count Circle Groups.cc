#include <iostream>
#include <cstring>

using namespace std;

int T,N;
pair<int,int> points[3001];
int R[3001];
bool visited[3001];

bool dfs(int n)
{
    if(visited[n]) return false;
    visited[n]=true;

    for(int i=1;i<=N;i++)
    {
        if(visited[i]) continue;

        int dx=points[n].first-points[i].first;
        int dy=points[n].second-points[i].second;
        if(dx*dx+dy*dy<=(R[n]+R[i])*(R[n]+R[i]))
            dfs(i);
    }
    
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int n=1;n<=N;n++)
            cin>>points[n].first>>points[n].second>>R[n];
            
        memset(visited,0,sizeof(visited));
        int ret=0;
        for(int n=1;n<=N;n++)
            if(dfs(n))
                ret++;

        cout<<ret<<"\n";
    }

    return 0;
}