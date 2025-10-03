#include <iostream>
#include <cstring>

#define MOD 1000000000

using namespace std;

int N,ret;
long long dp[10][101][1<<10];

void input()
{
    cin>>N;
}

long long dfs(int a,int len,int bit)
{
    if(dp[a][len][bit]!=-1) return dp[a][len][bit];
    if(len==N)
    {
        if(bit==(1<<10)-1) return 1;
        else return 0;
    }

    dp[a][len][bit]=0;
    for(int b:{a-1,a+1})
    {
        if(0<=b and b<=9)
        {
            dp[a][len][bit]+=dfs(b,len+1,bit|(1<<b));
            dp[a][len][bit]%=MOD;
        }
    }
    
    return dp[a][len][bit];
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=9;i++)
    {
        ret+=dfs(i,1,1<<i);
        ret%=MOD;
    }
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