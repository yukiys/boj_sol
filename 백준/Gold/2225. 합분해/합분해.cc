#include <iostream>

#define MOD 1000000000

using namespace std;

int N,K;
int dp[201][201];

void input()
{
    cin>>N>>K;
}

void solve()
{
    for(int n=1;n<=N;n++) dp[1][n]=1;
    for(int k=2;k<=K;k++) dp[k][1]=k;
    
    for(int k=2;k<=K;k++)
        for(int n=2;n<=N;n++)
            dp[k][n]=(dp[k-1][n]+dp[k][n-1])%MOD;
}

void printResult()
{
    cout<<dp[K][N]<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}