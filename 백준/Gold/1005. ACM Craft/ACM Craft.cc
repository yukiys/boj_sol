#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T,N,K,W;
vector<int> edges[1001];
int D[1001],degree[1001],dp[1001];

void input()
{
    cin>>N>>K;
    
    for(int i=1;i<=N;i++)
    {
        edges[i].clear();
        cin>>D[i];
        degree[i]=0;
        dp[i]=0;
    }

    for(int i=0;i<K;i++)
    {
        int X,Y;
        cin>>X>>Y;
        edges[X].push_back(Y);
        degree[Y]++;
    }

    cin>>W;
}

void solve()
{
    queue<int> q;

    for(int i=1;i<=N;i++)
    {
        if(degree[i]==0)
        {
            dp[i]=D[i];
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int cur=q.front();
        q.pop();

        for(int next:edges[cur])
        {
            if((--degree[next]==0)) q.push(next);
            dp[next]=max(dp[next],dp[cur]+D[next]);
        }
    }
}

void printResult()
{
    cout<<dp[W]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>T;
    while(T--)
    {
        input();
        solve();
        printResult();
    }

    return 0;
}