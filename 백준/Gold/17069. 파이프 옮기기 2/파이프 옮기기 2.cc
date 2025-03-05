#include <iostream>

using namespace std;

int N;
int map[33][33];
long long dp[33][33][3];

void solve()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=3;j<=N;j++)
        {
            if(map[i][j]==1) continue;

            dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][1];
            dp[i][j][2]=dp[i-1][j][1]+dp[i-1][j][2];
            if(map[i-1][j]==0 and map[i][j-1]==0)
                dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
        }
    }
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>map[i][j];

    dp[1][2][0]=1;

    solve();

    cout<<dp[N][N][0]+dp[N][N][1]+dp[N][N][2]<<"\n";

    return 0;
}