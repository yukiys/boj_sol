#include <iostream>
#include <numeric>

#define MOD 1000000007

using namespace std;

int M;
long long ret;

void input()
{
    cin>>M;
}

long long Mul(long long x,long long y)
{
    if(y==1) return x;

    if(y%2==1) return x*Mul(x,y-1)%MOD;

    long long z=Mul(x,y/2);
    return z*z%MOD;
}

void solve()
{
    for(int i=0;i<M;i++)
    {
        int N,S;
        cin>>N>>S;

        long long GCD=gcd(N,S);
        N/=GCD;
        S/=GCD;

        ret+=S*Mul(N,MOD-2)%MOD;
        ret%=MOD;
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