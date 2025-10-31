#include <iostream>

using namespace std;

long long N,ret;

void input()
{
    cin>>N;
    ret=N;
}

void solve()
{
    for(long long i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            ret-=ret/i;
            while(N%i==0) N/=i;
        }
    }
    if(N>1) ret-=ret/N;
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