#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T,N;
int sticker[2][100000];
int dp[2][100000];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>T;
    while(T--)
    {
        memset(dp,0,sizeof(dp));

        cin>>N;

        for(int i=0;i<2;i++)
            for(int j=0;j<N;j++)
                cin>>sticker[i][j];

        dp[0][0]=sticker[0][0];
        dp[1][0]=sticker[1][0];

        if(N>=2)
        {
            dp[0][1]=dp[1][0]+sticker[0][1];
            dp[1][1]=dp[0][0]+sticker[1][1];
        }
        
        for(int j=2;j<N;j++)
            for(int i=0;i<2;i++)
                dp[i][j]=max({dp[(i+1)%2][j-1],dp[i][j-2],dp[(i+1)%2][j-2]})+sticker[i][j];

        int Max=0;
        for(int i=0;i<2;i++)
            for(int j=0;j<N;j++)
                Max=max(Max,dp[i][j]);

        cout<<Max<<"\n";
    }

    return 0;
}