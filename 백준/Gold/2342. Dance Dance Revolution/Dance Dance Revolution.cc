#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int ret=INF;
vector<int> arr;
int dp[100001][5][5];
int cost[5][5]=
{
    {1,2,2,2,2},
    {2,1,3,4,3},
    {2,3,1,3,4},
    {2,4,3,1,3},
    {2,3,4,3,1}
};

void input()
{
    int a;
    while(cin>>a and a!=0) arr.push_back(a);
}

void solve()
{
    int N=arr.size();

    for(int i=0;i<=N;i++)
        for(int L=0;L<5;L++)
            for(int R=0;R<5;R++)
                dp[i][L][R]=INF;

    dp[0][0][0]=0;
    for(int idx=0;idx<N;idx++)
    {
        int next=arr[idx];

        for(int L=0;L<5;L++)
        {
            for(int R=0;R<5;R++)
            {
                if(dp[idx][L][R]==INF) continue;

                dp[idx+1][next][R]=min(dp[idx+1][next][R],dp[idx][L][R]+cost[L][next]);
                dp[idx+1][L][next]=min(dp[idx+1][L][next],dp[idx][L][R]+cost[R][next]);
            }
        }
    }

    for(int L=0;L<5;L++)
        for(int R=0;R<5;R++)
            ret=min(ret,dp[N][L][R]);
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    solve();
    printResult();

    return 0;
}