#include <iostream>

using namespace std;

#define MOD 1000000009

long long dp[1000001];

int main()
{
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<=1000000;i++) dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%MOD;

    int T; cin>>T;
    for(int t=0;t<T;t++)
    {
        int n; cin>>n;

        cout<<dp[n]%MOD<<"\n";
    }

    return 0;
}