#include <iostream>
#include <cstring>

#define INF 1e13

using namespace std;

int N;
int W[16][16];
long long ret=INF;
long long dp[16][1<<16];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>W[i][j];
}

long long dfs(int a,int bit)
{
    if(dp[a][bit]!=-1) return dp[a][bit];
    if(bit==(1<<N)-1)
    {
        if(W[a][0]==0) return INF;
        else return W[a][0];
    }

    dp[a][bit]=INF;
    for(int b=0;b<N;b++)
        if(a!=b and !(bit&(1<<b)) and W[a][b]!=0)
            dp[a][bit]=min(dp[a][bit],W[a][b]+dfs(b,bit|(1<<b)));

    return dp[a][bit];
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    ret=dfs(0,1<<0);
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