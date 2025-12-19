#include <iostream>
#include <vector>

using namespace std;

int N,ret;
int people[10001];
vector<int> G[10001];
bool visited[10001];
int dp[10001][2];

void input()
{
    cin>>N;
    for(int i=1;i<=N;i++) cin>>people[i];

    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

void dfs(int cur)
{
    visited[cur]=true;
    dp[cur][0]=0;
    dp[cur][1]=people[cur];

    for(int next:G[cur])
    {
        if(visited[next]) continue;

        dfs(next);
        
        dp[cur][0]+=max(dp[next][0],dp[next][1]);
        dp[cur][1]+=dp[next][0];
    }
}

void solve()
{
    dfs(1);
    ret=max(dp[1][0],dp[1][1]);
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}