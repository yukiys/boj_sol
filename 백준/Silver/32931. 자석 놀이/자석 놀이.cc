#include <iostream>

#define INF -1e18

using namespace std;

int N;
int grid[3][200001];
long long dp[4][200001];

void input()
{
    cin>>N;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=N;j++)
            cin>>grid[i][j];
}

void solve()
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=N;j++)
            dp[i][j]=INF;
    
    dp[1][1]=grid[1][1];
    dp[3][1]=grid[1][1]+grid[2][1];

    for(int i=2;i<=N;i++)
    {
        dp[1][i]=max(dp[1][i-1],dp[3][i-1])+grid[1][i];
        dp[2][i]=max(dp[2][i-1],dp[3][i-1])+grid[2][i];

        dp[3][i]=max(dp[1][i-1],max(dp[2][i-1],dp[3][i-1]))+grid[1][i]+grid[2][i];
    }
}

void printResult()
{
    cout<<max(dp[2][N],dp[3][N])<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}