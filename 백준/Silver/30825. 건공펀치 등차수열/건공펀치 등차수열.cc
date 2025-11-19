#include <iostream>

using namespace std;

int N,K;
int A[200000];
long long r[200000];
long long m,ret;

void input()
{
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>A[i];
}

void solve()
{
    r[0]=A[0];
    for(int i=1;i<N;i++) r[i]=r[i-1]+K;

    for(int i=0;i<N;i++)
    {
        ret+=r[i]-A[i];
        if(r[i]-A[i]<0)
        {
            m=min(m,r[i]-A[i]);
        }
    }
    
    ret-=N*m;
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