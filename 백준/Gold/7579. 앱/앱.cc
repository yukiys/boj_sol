#include <iostream>
#include <vector>

using namespace std;

int N,M,ret=1e9;
vector<pair<int,int>> MC;
int Max,dp[10001];

void input()
{
    cin>>N>>M;

    MC.resize(N);
    for(int i=0;i<N;i++) cin>>MC[i].first;
    for(int i=0;i<N;i++)
    {
        cin>>MC[i].second;
        Max+=MC[i].second;
    }
}

void solve()
{
    for(int i=0;i<=Max;i++) dp[i]=-1;
    
    dp[0]=0;
    for(int i=0;i<N;i++)
    {
        int M=MC[i].first;
        int C=MC[i].second;

        for(int c=Max;c-C>=0;c--)
            if(dp[c-C]!=-1)
                dp[c]=max(dp[c],dp[c-C]+M);
    }

    for(int c=0;c<=Max;c++)
    {
        if(dp[c]>=M)
        {
            ret=c;
            break;
        }
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