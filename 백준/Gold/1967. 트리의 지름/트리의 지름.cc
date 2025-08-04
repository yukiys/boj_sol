#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,idx;
vector<pair<int,int>> tree[10001];
bool visited[10001];

void dfs(int node,int dist)
{
    visited[node]=true;

    if(dist>M)
    {
        M=dist;
        idx=node;
    }

    for(int i=0;i<tree[node].size();i++)
    {
        int next=tree[node][i].first;
        int weight=tree[node][i].second;

        if(!visited[next]) dfs(next,dist+weight);
    }
}

int main()
{
    cin>>N;
    for(int i=0;i<N-1;i++)
    {
        int parent,child,weight;
        cin>>parent>>child>>weight;

        tree[parent].push_back({child,weight});
        tree[child].push_back({parent,weight});
    }

    dfs(1,0);

    fill(visited,visited+10001,false);

    dfs(idx,0);

    cout<<M<<"\n";

    return 0;
}