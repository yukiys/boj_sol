#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int N;
vector<int> triangle;
vector<int> cannon;
int dp[300001];

void input()
{
    cin>>N;
}

void solve()
{
    for(int i=1;(i+1)*i/2<=N;i++)
        triangle.push_back((i+1)*i/2);

    cannon.push_back(1);
    for(int i=1;cannon[i-1]+triangle[i]<=N;i++)
        cannon.push_back(cannon[i-1]+triangle[i]);

    dp[0]=0;
    for(int i=1;i<=N;i++) dp[i]=INF;

    for(int i=1;i<=N;i++)
        for(int j=0;j<cannon.size() and i-cannon[j]>=0;j++)
            dp[i]=min(dp[i],dp[i-cannon[j]]+1);
}

void printResult()
{
    cout<<dp[N]<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}