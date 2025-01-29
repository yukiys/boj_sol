#include <iostream>
#include <cstring>

using namespace std;

int N,M;
int coin[21];
int dp[10001];

int main()
{
    int T; cin>>T;
    for(int t=0;t<T;t++)
    {
        memset(dp,0,sizeof(dp));
        cin>>N;
        for(int n=1;n<=N;n++) cin>>coin[n];
        
        cin>>M;
        dp[0]=1;
        for(int i=1;i<=N;i++)
            for(int j=coin[i];j<=M;j++)
                dp[j]+=dp[j-coin[i]];
        
        cout<<dp[M]<<"\n";
    }

    return 0;
}