#include <iostream>

using namespace std;

int N,ret;
int A[1000],DP1[1000],DP2[1000];

void input()
{
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
}

void solve()
{
    for(int i=1;i<N;i++)
        for(int j=0;j<i;j++)
            if(A[j]<A[i])
                DP1[i]=max(DP1[i],DP1[j]+1);

    for(int i=N-2;i>=0;i--)
        for(int j=N-1;j>i;j--)
            if(A[j]<A[i])
                DP2[i]=max(DP2[i],DP2[j]+1);

    for(int i=0;i<N;i++) ret=max(ret,DP1[i]+DP2[i]);
    ret++;
}

void printResult()
{
    cout<<ret<<"\n";
}

int main()
{
    input();
    solve();
    printResult();

    return 0;
}