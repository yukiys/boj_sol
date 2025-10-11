#include <iostream>

#define INF 1e9

using namespace std;

int N,ret=INF;
int cost[1000][3],dp[1000][3];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<3;j++)
            cin>>cost[i][j];
}

void solve(int start)
{
    for(int i=0;i<3;i++)
    {
        if(i==start) dp[0][i]=cost[0][i];
        else dp[0][i]=INF;
    }

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<3;j++)
        {
            int next1=(j+1)%3;
            int next2=(j+2)%3;

            dp[i][j]=(dp[i-1][next1]<dp[i-1][next2])?dp[i-1][next1]:dp[i-1][next2];
            dp[i][j]+=cost[i][j];
        }
    }

    for(int i=0;i<3;i++)
        if(i!=start)
            ret=min(ret,dp[N-1][i]);
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    for(int start=0;start<3;start++) solve(start);
    printResult();

    return 0;
}