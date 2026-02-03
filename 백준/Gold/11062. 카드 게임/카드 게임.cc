#include <iostream>

using namespace std;

int T,N;
int cards[1001];
int Sum[1001];
int dp[1001][1001];

void init()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>cards[i];

    for(int i=0;i<N;i++)
        Sum[i+1]=Sum[i]+cards[i+1];

    for(int i=1;i<=N;i++)
        dp[i][i]=cards[i];
}

int getSum(int l,int r)
{
    if(l>r) return 0;
    return Sum[r]-Sum[l-1];
}

void solve()
{
    for(int len=2;len<=N;len++)
    {
        for(int l=1;l+len-1<=N;l++)
        {
            int r=len+l-1;

            int Left=cards[l]+getSum(l+1,r)-dp[l+1][r];
            int Right=cards[r]+getSum(l,r-1)-dp[l][r-1];

            dp[l][r]=max(Left,Right);
        }
    }
}

void printRet()
{
    cout<<dp[1][N]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>T;
    while(T--)
    {
        init();
        solve();
        printRet();
    }
}