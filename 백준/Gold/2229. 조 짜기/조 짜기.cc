#include <iostream>

using namespace std;

int N;
int score[1001];
int dp[1001];

void input()
{
    cin>>N;
    for(int i=1;i<=N;i++) cin>>score[i];
}

void solve()
{
    for(int i=1;i<=N;i++)
    {
        int m=score[i], M=score[i];
        for(int j=i;j>=1;j--)
        {
            m=min(m,score[j]);
            M=max(M,score[j]);
            
            dp[i]=max(dp[i],dp[j-1]+(M-m));
        }
    }
}

void printResult()
{
    cout<<dp[N]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}