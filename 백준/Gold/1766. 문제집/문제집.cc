#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<int> edges[32001];
int degree[32001];
int idx,ret[32001];

void input()
{
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        degree[b]++;
    }
}

void solve()
{
    priority_queue<int,vector<int>,greater<int>> q;

    for(int i=1;i<=N;i++)
        if(degree[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int cur=q.top();
        q.pop();
        ret[idx++]=cur;

        for(int next:edges[cur])
            if((--degree[next])==0)
                q.push(next);
    }
}

void printResult()
{
    for(int i=0;i<N;i++) cout<<ret[i]<<" ";
    cout<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}