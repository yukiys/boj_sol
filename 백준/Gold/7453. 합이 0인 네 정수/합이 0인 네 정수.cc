#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long ret;
long long A[4000],B[4000],C[4000],D[4000];
long long AB[4000*4000],CD[4000*4000];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i]>>B[i]>>C[i]>>D[i];
}

void solve()
{
    int idx=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            AB[idx++]=A[i]+B[j];

    idx=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            CD[idx++]=C[i]+D[j];

    sort(CD,CD+N*N);

    for(int i=0;i<N*N;i++)
    {
        auto range=equal_range(CD,CD+N*N,-AB[i]);
        ret+=(range.second-range.first);
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