#include <iostream>
#include <algorithm>

using namespace std;

int N,ret;
pair<int,int> A[500001],SA[500001];

void input()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int a;
        cin>>a;
        A[i].first=SA[i].first=a;
        A[i].second=SA[i].second=i;
    }
}

void solve()
{
    sort(SA+1,SA+1+N);

    for(int i=1;i<=N;i++)
    {
        int cur=i;
        int origin=SA[cur].second;
        ret=max(ret,origin-cur);
    }
}

void printResult()
{
    cout<<ret+1<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}