#include <iostream>
#include <vector>

const long long MOD=1e9+7;

using namespace std;

long long n,m,ret=1;
vector<pair<long long,long long>> factors;

void init()
{
    cin>>n>>m;
}

void factorize(long long num)
{
    for(long long p=2;p*p<=num;p++)
    {
        if(num%p==0)
        {
            long long cnt=0;
            while(num%p==0)
            {
                num/=p;
                cnt++;
            }
            factors.push_back({p,cnt});
        }
    }
    if(num>1) factors.push_back({num,1});
}

long long power(long long x,long long y)
{
    if(y==1) return x;

    if(y%2==1) return x*power(x,y-1)%MOD;

    long long z=power(x,y/2);
    return z*z%MOD;
}

void solve()
{
    if(n==1 or m==0) return;

    factorize(n);

    for(int i=0;i<factors.size();i++)
    {
        long long p=factors[i].first;
        long long cnt=factors[i].second;

        ret*=(power(p,m*cnt+1)-1+MOD)%MOD;
        ret%=MOD;
        ret*=power(p-1,MOD-2);
        ret%=MOD;
    }
}

void printRet()
{
    cout<<ret<<"\n";
}

int main()
{
    init();
    solve();
    printRet();
}