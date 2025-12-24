#include <iostream>
#include <vector>

#define MOD 123456789

using namespace std;

int N;
vector<int> prime;
int dp[40001];

void init()
{
    cin>>N;
    for(int i=2;i<=N;i++)
    {
        bool check=true;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                check=false;
                break;
            }
        }
        if(check) prime.push_back(i);
    }
}

void solve()
{
    dp[0]=1;
    for(int i=0;i<prime.size();i++)
    {
        int p=prime[i];
        for(int n=2;n<=N;n++)
        {
            if(n<p) continue;
            
            dp[n]+=dp[n-p];
            dp[n]%=MOD;
        }
    }
}

void printResult()
{
    cout<<dp[N]<<"\n";
}

int main()
{
    init();
    solve();
    printResult();
}