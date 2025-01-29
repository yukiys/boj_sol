#include <iostream>

using namespace std;

int N,K;
int I[1001];
int T[1001];
int dp[1001][10001];

int main()
{
    cin>>N>>K;
    for(int i=1;i<=K;i++)
        cin>>I[i]>>T[i];

    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(j>=T[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-T[i]]+I[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[K][N]<<"\n";

    return 0;
}