#include <iostream>

using namespace std;

int N,Q;
int T[512];
int ans[512][512];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>T[i];
}

void solve()
{
    int dp[512],ndp[512];

    for(int l=0;l<N;l++)
    {
        for(int i=0;i<512;i++) dp[i]=-1;

        dp[0]=0;
        int best=0;

        for(int r=l;r<N;r++)
        {
            for(int i=0;i<512;i++) ndp[i]=dp[i];
            int x=T[r];

            for(int i=0;i<512;i++)
            {
                if(dp[i]==-1) continue;

                if(ndp[i^x]<dp[i]+1)
                {
                    ndp[i^x]=dp[i]+1;
                    if(best<(i^x)+dp[i]+1) best=(i^x)+dp[i]+1;
                }
            }

            for(int i=0;i<512;i++) dp[i]=ndp[i];
            
            ans[l][r]=best;
        }
    }
}

void printResult()
{
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<ans[l-1][r-1]<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    solve();
    printResult();

    return 0;
}