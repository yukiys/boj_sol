#include <iostream>
#include <queue>
#include <vector>

#define MOD 1000000007

using namespace std;

int T,N;
priority_queue<long long,vector<long long>,greater<long long>> slimes;
long long ret;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        long long t;
        cin>>t;
        slimes.push(t);
    }
    ret=1;
}

void solve()
{
    while(slimes.size()>1)
    {
        long long a=slimes.top(); slimes.pop();
        long long b=slimes.top(); slimes.pop();
        long long c=(a*b);
        ret=((__int128_t)ret*c)%MOD;
        slimes.push(c);
    }
    slimes.pop();
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>T;
    while(T--)
    {
        input();
        solve();
        printResult();
    }

    return 0;
}