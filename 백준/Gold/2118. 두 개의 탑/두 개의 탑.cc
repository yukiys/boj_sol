#include <iostream>

using namespace std;

int N,T,ret;
int dist[50000];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>dist[i];
}

void solve()
{
    for(int i=0;i<N;i++) T+=dist[i];
    T/=2;

    int s=0,e=0,cur=0;
    while(s<N)
    {
        while(cur+dist[e]<=T)
        {
            cur+=dist[e];
            e=(e+1)%N;
        }
        ret=max(ret,cur);

        cur-=dist[s++];
    }
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