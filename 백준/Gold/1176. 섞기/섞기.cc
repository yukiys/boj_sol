#include <iostream>
#include <cstring>

using namespace std;

int N,K;
int height[16];
long long ret;
long long dp[16][1<<16];

void input()
{
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>height[i];
}

long long dfs(int a,int bit)
{
    if(dp[a][bit]!=-1) return dp[a][bit];
    if(bit==(1<<N)-1) return 1;

    dp[a][bit]=0;
    for(int b=0;b<N;b++)
        if(!(bit&(1<<b)) and abs(height[b]-height[a])>K)
            dp[a][bit]+=dfs(b,bit|(1<<b));
            
    return dp[a][bit];
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++) ret+=dfs(i,1<<i); 
}

void printResult()
{
    cout<<ret<<endl;
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}