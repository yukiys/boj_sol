#include <iostream>

#define MOD 1000000000

using namespace std;

int N,K;
int dp[5001][5001];


void input()
{
    cin>>N>>K;
}

void solve()
{
    for(int n=0;n<=N;n++) dp[1][n]=1;
    for(int k=1;k<=K;k++) dp[k][0]=1;

    for(int k=2;k<=K;k++)
        for(int n=1;n<=N;n++)
            dp[k][n]=(dp[k][n-1]+dp[k-1][n])%MOD;
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