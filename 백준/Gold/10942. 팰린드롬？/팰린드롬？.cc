#include <iostream>

using namespace std;

int N,M,S,E;
int A[2001];
int dp[2001][2001];

void input()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }
    cin>>M;
}

void solve()
{
    for(int i=1;i<=N;i++) dp[i][i]=1;
    for(int i=1;i+1<=N;i++)
    {
        if(A[i]==A[i+1]) dp[i][i+1]=1;
        else dp[i][i+1]=0;
    }
    
    for(int d=2;d<=N;d++)
        for(int i=1;i+d<=N;i++)
            if(dp[i+1][i+d-1]==1 and A[i]==A[i+d])
                dp[i][i+d]=1;
}

void printResult()
{
    for(int i=0;i<M;i++)
    {   
        cin>>S>>E;

        cout<<dp[S][E]<<"\n";
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