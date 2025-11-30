#include <iostream>

using namespace std;

int T,N,M,K,ret;
int money[100000];

void input()
{
    cin>>N>>M>>K;
    for(int i=0;i<N;i++) cin>>money[i];
    ret=0;
}

void solve()
{
    int start=0,end=M-1;
    long long sum=0;
    for(int i=0;i<M;i++) sum+=money[i];

    if(N==M)
    {
        if(sum<K) ret=1;
        else ret=0;
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(sum<K) ret++;

        sum-=money[start++];
        start%=N;
        sum+=money[(++end)%N];
        end%=N;
    }
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