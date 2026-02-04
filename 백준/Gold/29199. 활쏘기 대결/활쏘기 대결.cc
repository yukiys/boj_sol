#include <iostream>

using namespace std;

int N;
long long A[200001],Sum[200001];
long long dp[200001];

void init()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        Sum[i]=Sum[i-1]+A[i];
    }
}

void solve()
{
    for(int i=1;i<=N;i++)
        dp[i]=max(dp[i-1],Sum[i]-dp[i-1]);
}

void printRet()
{
    cout<<dp[N]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    init();
    solve();
    printRet();
}