#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V,idx,ret;
vector<pair<int,int>> tree[100001];
bool visited[100001];

void dfs(int start,int dist)
{
    visited[start]=true;

    if(dist>ret)
    {
        ret=dist;
        idx=start;
    }

    for(int i=0;i<tree[start].size();i++)
    {
        int next=tree[start][i].first;
        int weight=tree[start][i].second;

        if(!visited[next]) dfs(next,dist+weight);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>V;

    for(int i=0;i<V;i++)
    {
        int a,b,c;
        cin>>a;

        while(1)
        {
            cin>>b;
            if(b==-1) break;
            cin>>c;

            tree[a].push_back({b,c});
            tree[b].push_back({a,c});
        }
    }

    dfs(1,0);

    memset(visited,0,sizeof(visited));

    dfs(idx,0);

    cout<<ret<<"\n";

    return 0;
}